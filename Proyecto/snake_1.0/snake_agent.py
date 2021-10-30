import pygame
import random
from collections import namedtuple
from pygame import font

from pygame.version import PygameVersion
import direction as dir

BLOCK_SIZE = 20
SPEED = 40

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (200, 0, 0)
BLUE = (0, 0, 200)
LIGHT_BLUE = (0, 100, 255)


# Initialize pygame modules
pygame.init()

# Letter font
font = pygame.font.Font('arial.ttf', 25 )
Point = namedtuple('Point', 'x, y')

class SnakeAgent():
  def __init__(self, widht=640, height=480) -> None:
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
    self.snake = [self.head, 
                  Point(self.head.x - BLOCK_SIZE, self.head.y),
                  Point(self.head.x - (2 * BLOCK_SIZE), self.head.y)
                  ]  

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

    self.update_ui()
    self.clock.tick()

    game_over = False
    return game_over, self.score

  def update_ui(self):
    self.display.fill(BLACK)

    for point in self.snake:
      pygame.draw.rect(self.display, LIGHT_BLUE, pygame.Rect(point.x, point.y, BLOCK_SIZE, BLOCK_SIZE))
      pygame.draw.rect(self.display, BLUE, pygame.Rect(point.x + 4, point.y + 4, 12, 12))

    pygame.draw.rect(self.display, RED, pygame.Rect(self.food.x, self.food.y, BLOCK_SIZE, BLOCK_SIZE))

    text = font.render("Score: " + str(self.score), True, WHITE)
    self.display.blit(text, [0, 0])
    pygame.display.flip()

if __name__ == '__main__':
  agent = SnakeAgent()
  game_over = False

  while game_over == False:
    game_over, score = agent.play_step()

    # break if loose
  print('Final Score', score)

  pygame.quit()