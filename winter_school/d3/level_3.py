import pygame
import random
from pygame import mixer

pygame.init()
mixer.init()
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

font = pygame.font.SysFont("Arial", 30)

apple = pygame.image.load("/img/apple.png")
banana = pygame.image.load("/img/banana.png")
orange= pygame.image.load("/img/orange1.png")
gift = pygame.image.load("/img/gift.png")
basket = pygame.image.load("/img/basket.png")
bomb_1 = pygame.image.load("/img/bomb.png")
bomb = pygame.transform.scale(bomb_1, (40, 50))
mixer.music.load('/img/bonus.wav')


list_fruits = [apple, orange, banana, gift, bomb]

basket_x = 185
basket_y = 550
fruits = [[400, 0, apple]]
time_spawn = 70
time = 0
score = 0
hp = 3
speed = 60

running = True
while running:
    time += 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    buttons = pygame.key.get_pressed()

    if buttons[pygame.K_RIGHT] and basket_x < 700:
        basket_x += 5
    if buttons[pygame.K_LEFT] and basket_x > 0:
        basket_x -= 5
    if buttons[pygame.K_UP]:
        basket_y -= 5
    if buttons[pygame.K_DOWN]:
        basket_y += 5

    if time % 100 == 0:
        fruits.append([random.randint(40, 760),
                       -40,
                       random.choice(list_fruits)])
    if time % 200 == 0:
        fruits.append([random.randint(40, 760),
                       -40,
                       gift])

    if hp <= 0:
        text = font.render("Game over!", True, (255, 0, 0))
        screen.blit(text, (100, 250))
        pygame.display.flip()
        continue

    screen.fill((135, 206, 235))

    pygame.draw.rect(screen, (0, 255, 0), (0, 570, 800, 30))

    for f in fruits:
        screen.blit(f[2], (f[0], f[1]))
        f[1] += 2

        if f[1] > 555:
            fruits.remove(f)
            if f[2] != gift and f[2] != bomb:
                hp -= 1


        hit_box = pygame.Rect(f[0], f[1], f[2].get_width(), f[2].get_height())
        hit_basket = pygame.Rect(basket_x, basket_y, 100, 30)

        if hit_box.colliderect(hit_basket) :
            fruits.remove(f)
            if f[2] == gift:
                r = random.randint(0, 1)
                if r == 0:
                    score += 50
                else:
                    hp -= 1
            elif f[2] == bomb:
                hp -= 2
            else:
                score += 1
                if speed < 80:
                    speed += 5
            mixer.music.play()
            print(score)
        text_s = font.render(f"очки:{score}", True, (255, 0, 0))
        screen.blit(text_s, (50, 50))
        text_hp = font.render(f"жизни:{hp}", True, (255, 0, 0))
        screen.blit(text_hp, (50, 10))

    screen.blit(basket, (basket_x, basket_y))

    pygame.display.flip()
    clock.tick(60)

pygame.quit()