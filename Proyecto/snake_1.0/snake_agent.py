import pygame
import random
from collections import namedtuple
import direction as dir

BLOCK_SIZE = 20

# Initialize pygame modules
pygame.init()

Point = namedtuple('Point', 'x', 'y')

class SnakeAgent():
  def __init__(self, widht=640, height=480) -> None:
    self.widht = widht
    self.height = height

    # initialize display
    self.display = pygame.display.set_mode(self.widht, self.height)
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

    if self.food in self.snake:
      self.place_food()

  def play_step(self):
    pass



if __name__ == '__main__':
  agent = SnakeAgent()

  while True:
    agent.play_step()

    # break if loose

  pygame.quit()