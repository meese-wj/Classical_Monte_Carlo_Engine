# Classical Monte Carlo Engine
### W. Joe Meese

A general purpose Monte Carlo simulation engine for studies of canonical statistical mechanics. The algorithm assumes one is working with thermal ensembles where the transition probabilities are temperature-dependent, such as Metropolis-Hastings, Wolff, parallel-tempering algorithms, _etc_.

## Why this Repo?

Aren't there plenty of Monte Carlo libraries? Yes and no. There are plenty of deluxe Monte Carlo simulation that have been written by really great people. These are usually written so that others can really make great strides in computational science. 

However, there are fewer examples of scalable code for students first starting out in computational physics. There are plenty of examples of the 2D Ising model, for example, but these codes usually are written _exclusively_ for the 2D Ising model, and therefore they don't transfer well once a student gets out of the introductory phase. In other words, the available introductory examples typically do not provide a framework for someone to expand their own tested Monte Carlo code to new projects outside of the tutorial level. This is problematic because then there is plenty of copied or rewritten code and projects that are ultimately difficult to build upon or reproduce.

This repository is meant to be more pedagogical than production-level. My goal is to write a powerful and generalizable Monte Carlo code using intelligible C++. I will personally use this repo to test my own new ideas and new models, but I will try to maintain it in a way that it remains true to its primary purpose: to be scaffolding for any new computational scientists trying to write their own long-term projects.

## Installation and minimal example

__Disclaimer__: This repo is still a work in progress and I'll try to update this section as I go along.

### Installation

This code uses `CMake` as a build system. The point here is to separate the source code in [src/](src) and any of the compiled code which normally are placed into a `build` directory. 

First things first: `cd` into your preferred parent folder which will house this Git clone. Then execute these commands:

```bash
$ git clone https://github.com/meese-wj/Classical_Monte_Carlo_Engine.git

$ cd Classical_Monte_Carlo_Engine

$ mkdir build

$ cd build

$ cmake ..

$ cmake --build .
```

Now you should have a minimal example code built with all the default settings selected and are ready to run it.

### Running your first example Monte Carlo code

```c++
/* intentionally empty */
```

(I need code first :stuck-out-tongue:)