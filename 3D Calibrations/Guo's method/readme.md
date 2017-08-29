### Guo's 3D Calibrations  
Guo's method is to obtain the 3D calibration coefficient by applying the normalization value and using the least squares method. In this experiment, the distance between the reference plane and each plane was used as the normalization value and two coefficients were used. The 3D calibration coefficient can be obtained by applying the least squares method using the phase difference between the reference plane and each plane and the actual distance. In the figure below, there are n planes starting from the reference plane and the height of the reference plane is indicated by ![hi](http://i.imgur.com/R2InV3p.jpg).

<p align="center">
 <img src="System.JPG" alt="system" width = "400" display="block" margin="0 auto"  />
</p>


The method of calculating the coefficient using the least squares method is as follows.  
<p align="center">
 <img src="guo's equations.JPG" alt="equation1" width = "600" display="block" margin="0 auto"  />
</p>

In equation 1, ![c0](http://i.imgur.com/OHObKk9.jpg) and![c1](http://i.imgur.com/xH3vyUT.jpg) means the 3D calibration coefficients. This can be calculated by the formulas from Eqs. (2) to (4). ![delta_phi](http://i.imgur.com/CWNxHJS.jpg) means the phase difference between the reference plane and the i-th plane. h denotes the actual distance between the reference plane and the i-th plane, and n denotes the total number of the planes. The 3D calibration coefficient can be obtained by using the least square method using the phase difference and the actual distance as described above. This coefficient is a coefficient to be obtained for every pixel of the entire image. That is, there are two coefficients for each pixel, and the height value can be calculated using this.  

### Height calculation  
Now, we can obtain the height for the input phase value by using the coefficient for height measurement for each pixel. The formula for calculating the height value is shown in Equation (5).  

<p align="center">
 <img src="guo's equations2.JPG" alt="equation2" width = "500" display="block" margin="0 auto"  />
</p>

![hxy](http://i.imgur.com/zSnVj2I.jpg) denotes the height of the pixel ![xy](http://i.imgur.com/on7znib.jpg), and B denotes the phase difference between the reference plane and the object image to be measured at the pixel ![xy](http://i.imgur.com/on7znib.jpg). Also, ![c0xy](http://i.imgur.com/m9v3jpL.jpg) and ![c1xy](http://i.imgur.com/1SQKphV.jpg) represents the 3D calibration coefficient obtained previously.
