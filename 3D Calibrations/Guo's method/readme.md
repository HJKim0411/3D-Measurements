<!doctype html>
<html>
<head>
  <meta charset="UTF-8">
  <script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
</head>
<body data-document>&nbsp;</body>
</html>  




### Guo's 3D Calibrations  
Guo's method is to obtain the 3D calibration coefficient by applying the normalization value and using the least squares method. In this experiment, the distance between the reference plane and each plane was used as the normalization value and two coefficients were used. The 3D calibration coefficient can be obtained by applying the least squares method using the phase difference between the reference plane and each plane and the actual distance. In the figure below, there are n planes starting from the reference plane and the height of the reference plane is indicated by $h_i$.  

<p align="center">
 <img src="System.JPG" alt="system" width = "400" display="block" margin="0 auto"  />
</p>


The method of calculating the coefficient using the least squares method is as follows.  
<p align="center">
 <img src="guo's equations.JPG" alt="equation1" width = "600" display="block" margin="0 auto"  />
</p>

In equation 1, $c_0$ and $c_1$ means the 3D calibration coefficients. This can be calculated by the formulas from Eqs. (2) to (4). $ \Delta \phi $ means the phase difference between the reference plane and the $i$-th plane. $h$ denotes the actual distance between the reference plane and the $i$-th plane, and $n$ denotes the total number of the planes. The 3D calibration coefficient can be obtained by using the least square method using the phase difference and the actual distance as described above. This coefficient is a coefficient to be obtained for every pixel of the entire image. That is, there are two coefficients for each pixel, and the height value can be calculated using this.  

### Height calculation  
Now, we can obtain the height for the input phase value by using the coefficient for height measurement for each pixel. The formula for calculating the height value is shown in Equation (5).  

<p align="center">
 <img src="guo's equations2.JPG" alt="equation2" width = "500" display="block" margin="0 auto"  />
</p>

$h(x,y)$ denotes the height of the pixel $(x,y)$, and B denotes the phase difference between the reference plane and the object image to be measured at the pixel $(x,y)$. Also, $c_0(x,y)$ and $c_1(x,y)$ represents the 3D calibration coefficient obtained previously.
