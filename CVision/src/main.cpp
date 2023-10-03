#include <array>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat image = cv::imread("/home/amire/catkin_ws/src/beckhoff_ros/repo/IMG_5201.MOV/frame_cropped.jpg", cv::IMREAD_UNCHANGED);

    std::vector<unsigned char> array;

    // if (image.isContinuous()) 
    // {
    //     // array.assign(image.datastart, image.dataend); // <- has problems for sub-imagerix like image = big_image.row(i)
    //     array.assign(image.data, image.data + image.total()*image.channels());
    // } 
    // else 
    // {
    //     for (int i = 0; i < image.rows; ++i) {
    //         array.insert(array.end(), image.ptr<unsigned char>(i), image.ptr<unsigned char>(i)+image.cols*image.channels());
    //     }
    // }

    cv::Mat flat = image.reshape(1, image.total()*image.channels());
    std::array<unsigned char, 3*10*10> vec = image.isContinuous()? flat : flat.clone();

    for(int i =0; i<10; i++)
    {
        std::cout << vec.size() << "\n";
    }
       
    cv::imshow("3D Array as Image", image);
    cv::waitKey(0);

    return 0;
}