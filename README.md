# Simple-DIP
Simple digital image processing using C language, we borrow some code from [Darknet](https://github.com/pjreddie/darknet).

### How to use

1. build the source code

   ```
   mkdir build && cd build
   cmake ..
   make -j
   ```



2. perform exe file

   ```
   ./soble_edge --image_path hello//xxx.jpg
   ```

### Results


 <table align="center">
  <tr>
    <td><img src="doc/lena.jpg" width="256" height="256"></td>
    <td><img src="doc/outputs/lena-sobel-edge.jpg" width="256" height="256"></td>
  </tr>
  <tr>
    <td>Lena.jpg</td>
    <td>Lena_sobel_edge.jpg</td>
  </tr>
</table>
