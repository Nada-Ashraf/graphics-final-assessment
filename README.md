# Computer graphics final assessment report

<br />
<p align="center">
  <a href="https://github.com/Nada-Ashraf/graphics-final-assessment">
    <img src="./report/opengl_logo.png" alt="Logo" width="30%" height="30%">
  </a>

  <p align="center" style="font-family: times, serif; font-size:14pt; font-style:italic">
    Computer graphics final assessment
  </p>

<div align="center">

[![GitHub issues](https://img.shields.io/github/contributors/Nada-Ashraf/graphics-final-assessment)](https://github.com/Nada-Ashraf/graphics-final-assessment/contributors)
[![GitHub issues](https://img.shields.io/github/issues/Nada-Ashraf/graphics-final-assessment)](https://github.com/Nada-Ashraf/graphics-final-assessment/issues)
[![GitHub forks](https://img.shields.io/github/forks/Nada-Ashraf/graphics-final-assessment)](https://github.com/Nada-Ashraf/graphics-final-assessment/network)
[![GitHub stars](https://img.shields.io/github/stars/Nada-Ashraf/graphics-final-assessment)](https://github.com/Nada-Ashraf/graphics-final-assessment/stargazers)
[![GitHub license](https://img.shields.io/github/license/Nada-Ashraf/graphics-final-assessment)](https://github.com/Nada-Ashraf/graphics-final-assessment/master/LICENSE)

</div>

  <p align="center" style="font-family: times, serif; font-size:14pt; font-style:italic">
    <Strong> Group No. 7 </Strong>
    <br/>
    Nada Ashraf
    <br/>
    Khalid Maher
    <br/>
    Ali Gamal
  </p>
</p>

## About the project

## Snapshots

## Dependencies

## Compile and run

`sh compile_run.sh`

## Keyboard controls

### Animation

| Animation           | key |
| ------------------- | :-: |
| Robot Walking       |  n  |
| Robot Staning       |  m  |
| Robot Running       |  b  |
| Robot Turning Left  |  z  |
| Robot Turning Right |  x  |
| Robot Killing a man |  k  |

### Camera

| Animation       | key |
| --------------- | :-: |
| Moving Forward  |  w  |
| Moving Backward |  s  |
| Turning Right   |  d  |
| Turning Left    |  a  |
| Turning Up      |  q  |
| Turning Down    |  e  |

## Objects

There's 2 objects used in the application:

1. Object of a man who get killed by the robot
2. Object of a sword which the robot use to kill the man

## Textures

The user can change between several textures using a menu opens on right click.

## Implementation details

### Camera

- For camera movements we used the function `rotate()` which for transformation to be applied to all scene points, the function, we send `axis of rotation` and `angle of rotation` each call

- For `turn_up()` , `turn_down()` movements, we call `rotate()` function twice, once with `eye` vector and the other with `up` vector.

- For `turn_right()` , `turn_left()` movements, we call `rotate()` function only one time with the `eye` vector since the vertical direction with of the camera is parallel to the `Up` vector so what we need to do is to rotate all scene around up vector (only the eye is changed).

### Body

## Acknowledgements
