<h1 align="center">
  Maze
</h1>

## <a name='summary'> Summary</a>

* [Rules](#rules)
* [Overview](#overview)
* [Story](#story)
* [Bonus](#bonus)
* [Credits](#credits)

## <a name='rules'> Rules</a>

Hi, here are some rules to carry out this story oav;

* You **MUST** create a git repository named `maze`
* You **MUST** create a file called `.author.json` with your fullname

```sh
~/efrei-courses/learn-algorithm/exams/maze ❯❯❯ cat -e .author.json
[
  {
    "firstName": "Dylan",
    "lastName": "DE SOUSA"
  },
  {
    "firstName": "John",
    "lastName": "DOE"
  }
]$
```
* You **MUST** return the project on Friday March, 18 at 23:42 pm.<br />
* You **MUST** return a **Dockerfile**

## <a name='overview'>Overview</a>

The purpose of this project is simple, you **MUST** create a binary or a script that take any textual map file that represent a labyrinth and you have to output the labyrinth with a trace of the labyrinth solution.
```sh
❯ time ./maze.ts ./data/maps/rect.07.map

real   0m0,030s
user   0m0,020s
sys    0m0,012s
```

### Run with Docker
```sh
~/learn-algorithm/exams/maze/docker > docker compose up --build
...
```

## <a name='story'>Story</a>

### Prelude

As a programming pragmatic module, you **CAN** use the programming language you want/love.<br />
The only thing is that you must provide a **Dockerfile** that run your project ;)

### Algorithm

Your challenge is to have the best algorithm of your class ! <br />
I will check the execution time of your program, and you will get points according to your position :)

## <a name='bonus'> Bonus</a>

* Handle not squared map like [this oval map](./data/maps/oval_01.map)
* Improve the graphics

## <a name='credits'> Credits</a>

Craft by **Call-Me-Dev**.
