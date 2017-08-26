Prior to entering...
---


### About .cpp files...
- make_fringe_image.cpp : 'makeFringeImage' function makes the fringe pattern image.  Belows's image is a example of fringe pattern image( parameter T = 48 & vertical ). Also, 'makeFringeImage_gamma' function makes a gamma-corrected fringe pattern image. This is because sometimes the fringe pattern projected by project is distorted by gamma.  

<p align="center">
 <img src="48_hor00.bmp" alt="fringe pattern image" width = "400" display="block" margin="0 auto"  />
</p>

- calc_phase_value_0_2Pi.cpp : 'calc_phase_value_0_2Pi' function calculates the phase values. Prior to calculateing, you have to project the fringe pattern images and grab the images.
