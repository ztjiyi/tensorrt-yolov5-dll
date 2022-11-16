#include"pch.h"
class CLASS_DECLSPEC yolov5_dy
{
public:
	yolov5_dy();
	~yolov5_dy();

public:
	yolov5fz* Create_YOLOV5_Object();
	void Delete_YOLOV5_Object(yolov5fz* _bp);
};