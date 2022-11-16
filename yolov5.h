#include "pch.h"

using namespace std;
using namespace cv;

#define USE_FP16  // set USE_INT8 or USE_FP16 or USE_FP32
#define DEVICE 0  // GPU id
#define NMS_THRESH 0.4
#define CONF_THRESH 0.5
#define BATCH_SIZE 1
#define MAX_IMAGE_INPUT_SIZE_THRESH 3000 * 3000 // ensure it exceed the maximum size in the input images !


class CLASS_DECLSPEC Connect
{
public:
	Connect();
	~Connect();

public:
	yolov5fz* Create_YOLOV5_Object();
	void Delete_YOLOV5_Object(yolov5fz* _bp);
};

class yolov5 :public yolov5fz
{
public:
	yolov5();
	~yolov5();
	bool initialization(string& engine_name, int input_h, int input_w, int class_num);
	std::vector<s_result>&  get_result(cv::Mat& img);
private:
	int INPUT_H;
	int INPUT_W;
	int CLASS_NUM;
	int OUTPUT_SIZE;
	char* INPUT_BLOB_NAME;
	char* OUTPUT_BLOB_NAME;
	void* buffers[2];
	float* data;
	float* prob;
	Logger gLogger;
	IExecutionContext* context;
	cudaStream_t stream;
private:
	void doInference(IExecutionContext& context, cudaStream_t& stream, void** buffers, float* input, float* output, int batchSize);
	void get_roi(float res_roi[4],cv::Mat& img, float bbox[4]);
	float iou(float lbox[4], float rbox[4]);
	void nms(std::vector<Yolo::Detection>& res, float* output, float conf_thresh, float nms_thresh = 0.5);
};


inline bool cmpp(const Yolo::Detection& a, const Yolo::Detection& b) {
	return a.conf > b.conf;
};
