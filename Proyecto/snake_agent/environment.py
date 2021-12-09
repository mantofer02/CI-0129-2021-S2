import pygame
import random
import numpy as np
from collections import namedtuple
from pygame import font

from pygame.version import PygameVersion
import direction as dir

BLOCK_SIZE = 20
SPEED = 50

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

class SnakeEnvironment():
  def __init__(self, widht=640, height=480) -> None:
    self.speed = SPEED
    self.widht = widht
    self.height = height

    # initialize display
    self.display = pygame.display.set_mode((self.widht, self.height) )
    pygame.display.set_caption('Snake Game')
    self.clock = pygame.time.Clock()

    # initialize game state
    self.reset()

  def reset(self):
    # initialize game state
    # Set up variables and snake order
    self.direction = dir.Direction.RIGHT

    self.head = Point(self.widht/2, self.height/2)
    print("snake")
    self.snake = [self.head, Point(self.head.x - BLOCK_SIZE, self.head.y), Point(self.head.x-(2*BLOCK_SIZE), self.head.y)]  
    print(self.snake)

    self.score = 0
    self.frame_iteration = 0
    self.food = None
    self.place_food()

  # To do: Change recursion
  def place_food(self):
    x = random.randint(0, (self.widht - BLOCK_SIZE)//BLOCK_SIZE)*BLOCK_SIZE
    y = random.randint(0, (self.height - BLOCK_SIZE)//BLOCK_SIZE)*BLOCK_SIZE
    self.food = Point(x, y)

    if self.food in self.snake:
      self.place_food()

  def play_step(self, action):
    # Get events in the game / user inputs
    self.frame_iteration += 1

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
          pygame.quit()
          quit()

        

    self.move(action)
    self.snake.insert(0, self.head)

    reward = 0
    game_over = False
    if self.is_collision() or self.frame_iteration > 100 * len(self.snake):
      game_over = True
      reward = -10
      return game_over, self.score, reward, self.frame_iteration

    if self.head == self.food:
      self.score += 1
      reward += 10
      #self.speed += 2
      self.place_food()
    else:
      self.snake.pop()

    self.update_ui()
    self.clock.tick(self.speed)

    return game_over, self.score, reward, self.frame_iteration

  def update_ui(self):
    self.display.fill(BLACK)

    for point in self.snake:
      pygame.draw.rect(self.display, LIGHT_GREEN, pygame.Rect(point.x, point.y, BLOCK_SIZE, BLOCK_SIZE))
      pygame.draw.rect(self.display, GREEN, pygame.Rect(point.x + 4, point.y + 4, 12, 12))

    pygame.draw.rect(self.display, RED, pygame.Rect(self.food.x, self.food.y, BLOCK_SIZE, BLOCK_SIZE))

    text = font.render("Score: " + str(self.score), True, WHITE)
    self.display.blit(text, [0, 0])
    pygame.display.flip()

  def move(self, action):
    # [straight, right, left]
    clock_wise = [dir.Direction.RIGHT, dir.Direction.DOWN, dir.Direction.LEFT, dir.Direction.UP]
    index = clock_wise.index(self.direction)

    if np.array_equal(action, [1, 0, 0]):
      new_direction = clock_wise[index]
    
    elif np.array_equal(action, [0, 1, 0]):
      # right turn
      next_index =  (index + 1) % 4
      new_direction = clock_wise[next_index]

    else:
      # left turn
      next_index =  (index - 1) % 4
      new_direction = clock_wise[next_index]

    self.direction = new_direction

    x = self.head.x
    y = self.head.y
    if self.direction == dir.Direction.RIGHT:
      x += BLOCK_SIZE
    elif self.direction == dir.Direction.LEFT:
      x -= BLOCK_SIZE
    elif self.direction == dir.Direction.DOWN:
      y += BLOCK_SIZE
    elif self.direction == dir.Direction.UP:
      y -= BLOCK_SIZE

    self.head = Point(x, y)

  # To do: check beacause it detects collision when none taken
  def is_collision(self, pt=None):
    if pt is None:
      pt = self.head
    # To Do: Fix soo snake can go around game
    if pt.x > self.widht - BLOCK_SIZE or pt.x < 0 or pt.y > self.height - BLOCK_SIZE or pt.y < 0:
      return True
    
    if self.head in self.snake[1:]:
      # print(self.head)
      # print(self.snake)
      return True
    
    return False

