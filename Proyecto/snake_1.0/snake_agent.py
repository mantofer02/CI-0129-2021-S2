import pygame
import random

# Initialize pygame modules
pygame.init()

class SnakeAgent():
  def __init__(self, widht=640, height=480) -> None:
    self.widht = widht
    self.height = height

    #initialize display


    #initialize game state

  def play_step(self):
    pass



if __name__ == '__main__':
  agent = SnakeAgent()

  while True:
    agent.play_step()

    # break if loose

  pygame.quit()