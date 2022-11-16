#include "pch.h"
#include"yolov5_dy.h"
#include"yolov5.h"

yolov5_dy::yolov5_dy()
{}
yolov5_dy::~yolov5_dy()
{}
yolov5fz* yolov5_dy::Create_YOLOV5_Object()
{
    return new yolov5;      //注意此处
}
void yolov5_dy::Delete_YOLOV5_Object(yolov5fz* _bp)
{
    if (_bp)
        delete _bp;
}