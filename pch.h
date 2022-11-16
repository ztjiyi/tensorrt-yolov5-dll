// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"
#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>
#include "common.hpp"
#include <vector>
#include <fstream>
#include <string.h>
#include "yololayer.h"
#include "cuda_utils.h"
#include "logging.h"
#include "utils.h"
#include "calibrator.h"

using namespace std;
using namespace cv;

struct alignas(float) s_result {
	float bbox[4];// x0,y0,x1,y1
	//float conf;置信度
	float class_id;
};

#define CLASS_DECLSPEC __declspec(dllexport)//表示这里要把类导出//
class CLASS_DECLSPEC yolov5fz
{
public:
	yolov5fz() {};
	virtual  ~yolov5fz() {};
public:
	virtual  bool initialization(string& engine_name, int input_h, int input_w, int class_num)=0;
	virtual  std::vector<s_result>&  get_result(cv::Mat& img)=0;

};
#endif //PCH_H
