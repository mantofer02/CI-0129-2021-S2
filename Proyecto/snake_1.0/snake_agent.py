import pygame
import random
from collections import namedtuple
from pygame import font
import numpy as np
import os
import csv
import time
from pygame.version import PygameVersion
import direction as dir

BLOCK_SIZE = 20
SPEED = 7
SPEED_INCREASE = 1
SESSION_AMOUNT = 5

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 0, 0)
GREEN = (0, 102, 0)
LIGHT_GREEN = (128, 255, 0)


# Initialize pygame modules
pygame.init()

# Letter font
font = pygame.font.Font('arial.ttf', 25 )
Point = namedtuple('Point', 'x, y')

class SnakeAgent():
  def __init__(self, widht=640, height=480) -> None:
    self.speed = SPEED
    self.widht = widht
    self.height = height

    # initialize display
    self.display = pygame.display.set_mode((self.widht, self.height) )
    pygame.display.set_caption('Snake Game')
    self.clock = pygame.time.Clock()

    # initialize game state
    # Set up variables and snake order
    self.direction = dir.Direction.RIGHT

    self.head = Point(self.widht/2, self.height/2)
    print("snake")
    self.snake = [self.head, Point(self.head.x - BLOCK_SIZE, self.head.y), Point(self.head.x-(2*BLOCK_SIZE), self.head.y)]  
    print(self.snake)

    self.score = 0
    self.food = None
    self.place_food()

  # To do: Change recursion
  def place_food(self):
    x = random.randint(0, (self.widht - BLOCK_SIZE)//BLOCK_SIZE)*BLOCK_SIZE
    y = random.randint(0, (self.height - BLOCK_SIZE)//BLOCK_SIZE)*BLOCK_SIZE
    self.food = Point(x, y)

    if self.food in self.snake:
      self.place_food()

  def play_step(self):
    # Get events in the game / user inputs
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
          pygame.quit()
          quit()
        if event.type == pygame.KEYDOWN:
          if event.key == pygame.K_LEFT:
            self.direction = dir.Direction.LEFT
          elif event.key == pygame.K_RIGHT:
            self.direction = dir.Direction.RIGHT
          elif event.key == pygame.K_UP:
            self.direction = dir.Direction.UP
          elif event.key == pygame.K_DOWN:
            self.direction = dir.Direction.DOWN

    self.move(self.direction)
    self.snake.insert(0, self.head)

    game_over = False
    if self.is_collision():
      game_over = True
      return game_over, self.score

    if self.head == self.food:
      self.score += 1
      self.speed += SPEED_INCREASE
      self.place_food()
    else:
      self.snake.pop()

    self.update_ui()
    self.clock.tick(self.speed)

    return game_over, self.score

  def update_ui(self):
    self.display.fill(BLACK)

    for point in self.snake:
      pygame.draw.rect(self.display, LIGHT_GREEN, pygame.Rect(point.x, point.y, BLOCK_SIZE, BLOCK_SIZE))
      pygame.draw.rect(self.display, GREEN, pygame.Rect(point.x + 4, point.y + 4, 12, 12))

    pygame.draw.rect(self.display, RED, pygame.Rect(self.food.x, self.food.y, BLOCK_SIZE, BLOCK_SIZE))

    text = font.render("Score: " + str(self.score), True, WHITE)
    self.display.blit(text, [0, 0])
    pygame.display.flip()

  def move(self, direction):
    x = self.head.x
    y = self.head.y
    if direction == dir.Direction.RIGHT:
      x += BLOCK_SIZE
    elif direction == dir.Direction.LEFT:
      x -= BLOCK_SIZE
    elif direction == dir.Direction.DOWN:
      y += BLOCK_SIZE
    elif direction == dir.Direction.UP:
      y -= BLOCK_SIZE

    self.head = Point(x, y)

  # To do: check beacause it detects collision when none taken
  def is_collision(self):
    if self.head.x > self.widht - BLOCK_SIZE or self.head.x < 0 or self.head.y > self.height - BLOCK_SIZE or self.head.y < 0:
      return True
    
    if self.head in self.snake[1:]:
      return True
    
    return False

  def is_collision(self, pt=None):
    if pt is None:
      pt = self.head
    if pt.x > self.widht - BLOCK_SIZE or pt.x < 0 or pt.y > self.height - BLOCK_SIZE or pt.y < 0:
      return True
    
    if self.head in self.snake[1:]:
      return True
    
    return False

  def get_state(self):
    head = self.snake[0]
    point_l = Point(head.x - 20, head.y)
    point_r = Point(head.x + 20, head.y)
    point_u = Point(head.x, head.y - 20)
    point_d = Point(head.x, head.y + 20)

    dir_l = self.direction == dir.Direction.LEFT
    dir_r = self.direction == dir.Direction.RIGHT
    dir_u = self.direction == dir.Direction.UP
    dir_d = self.direction == dir.Direction.DOWN

    state = [
      # Danger straight
      (dir_r and self.is_collision(point_r)) or
      (dir_l and self.is_collision(point_l)) or
      (dir_u and self.is_collision(point_u)) or
      (dir_d and self.is_collision(point_d)),

      # Danger right
      (dir_r and self.is_collision(point_d)) or
      (dir_l and self.is_collision(point_u)) or
      (dir_u and self.is_collision(point_r)) or
      (dir_d and self.is_collision(point_l)),

      # Danger left
      (dir_r and self.is_collision(point_u)) or
      (dir_l and self.is_collision(point_d)) or
      (dir_u and self.is_collision(point_l)) or
      (dir_d and self.is_collision(point_r)),

      # Move direction
      dir_l,
      dir_r,
      dir_u,
      dir_d,

      self.food.x < self.head.x, # food left
      self.food.x > self.head.x, # food right
      self.food.y < self.head.y, # food up
      self.food.y > self.head.y, # food down

      self.speed,
      self.score
    ]

    return np.array(state, dtype=int)

def save_data(data, file_name):
  data_folder_path = './data'
  column_labels = [
    'danger_straight', 'danger_right', 'danger_left', 'dir_left', 'dir_right', 'dir_up', 'dir_down', 
    'food_left', 'food_right', 'food_up', 'food_down',
    'speed', 'score'
    ]

  if not os.path.exists(data_folder_path):
    os.makedirs(data_folder_path)

  with open(data_folder_path + str('/') + file_name + str('.csv'), 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(column_labels)
    for i in data:
      writer.writerow(i)

def save_results(results, file_name):
  data_folder_path = './game_results'
  if not os.path.exists(data_folder_path):
    os.makedirs(data_folder_path)
  
  column_labels = ['score', 'frame_count']

  with open(data_folder_path + str('/') + file_name + str('.csv'), 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(column_labels)
    for i in results:
      writer.writerow(i)





if __name__ == '__main__':
  print('Enter user name')
  file_name = input()
  
  results = []
  for i in range(SESSION_AMOUNT): 
    data = []
    game_results = []

    agent = SnakeAgent()
    game_over = False
    while game_over == False:
      game_over, score = agent.play_step()
      data.append(agent.get_state())
   
    game_results.append(score)
    game_results.append(len(data))
    results.append(game_results)
    print('Final Score', score)
    save_data(data, file_name + str('_') + str(i + 1))
  
  save_results(results, file_name)

  pygame.quit()