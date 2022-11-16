// yolov5_cs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "yolov5.h"
#include <vector>
#include <string.h>
#include "dirent.h"

int main()
{
    Connect connect;
    yolov5fz* yolov5_1 = connect.Create_YOLOV5_Object();
    string eiginePath = "yolov5s.engine";
    
    if (yolov5_1->initialization(eiginePath, 640, 640, 22))
    {
        std::cout << "Hello World!\n";
    }
	vector<cv::String> vImgPath;
	string filter = "img\\*.jpg";
	glob(filter, vImgPath);
	std::vector<s_result> img_res;
	cv::VideoCapture capture("D:\\c++\\tensor_yv5\\Release\\a.mp4");
	if (!capture.isOpened())
	{
		return -1;
	}
	cv::Mat img;
	capture.read(img);
	size_t  size_image = img.cols * img.rows * 3;
	//size_t  size_image_dst = INPUT_H * INPUT_W * 3;
    std::cout << capture.isOpened() << std::endl;
    int fcount = 0;
    while (capture.isOpened())
    {
        capture.read(img);
        if (img.channels() == 1)
        {
            cvtColor(img, img, cv::COLOR_GRAY2BGR);
        }
        img_res = yolov5_1->get_result(img);
        for (size_t j = 0; j < img_res.size(); j++) {
            cv::Rect r = cv::Rect(img_res[j].bbox[0], img_res[j].bbox[1], img_res[j].bbox[2] - img_res[j].bbox[0], img_res[j].bbox[3] - img_res[j].bbox[1]);
            cv::rectangle(img, r, cv::Scalar(0x27, 0xC1, 0x36), 2);
            cv::putText(img, std::to_string((int)img_res[j].class_id), cv::Point(r.x, r.y - 1), cv::FONT_HERSHEY_PLAIN, 1.2, cv::Scalar(0xFF, 0xFF, 0xFF), 2);
        }
        cv::imshow("a", img);
        cv::waitKey(25);
        /*
        struct alignas(float) Detection {
        float bbox[LOCATIONS];
        float conf;  // bbox_conf * cls_conf
        float class_id;
        };
        */
        // auto& res = batch_res[0];
    
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
