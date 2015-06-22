#ifndef INC_PARAMS_H
#define INC_PARAMS_H

#include <opencv2/opencv.hpp>
using namespace cv;

struct HOGParams
{
	int transBinSize;
	int scaleBinSize;
	int nOrients;
	int softBin;
	float clipHog;
	HOGParams()
	{
		transBinSize = 1;
		scaleBinSize = 4;
		nOrients = 9;
		clipHog = 0.2;
		softBin = -1;
	}
};

struct GT
{
	double tlx_;
	double tly_;
	double trx_;
	double try_;
	double blx_;
	double bly_;
	double brx_;
	double bry_;
};

struct trackingSetup
{
	cv::Mat trans_cos_win;
	cv::Mat scale_cos_win;

	cv::Mat transFourier;
	cv::Mat scaleFourier;

	int nNumTrans;
	cv::Mat *num_trans;
	cv::Mat den_trans;
	int nNumScale;
	cv::Mat *num_scale;
	cv::Mat den_scale;

	double *scaleFactors;
	Size scale_model_sz;

	float min_scale_factor;
	float max_scale_factor;

	float current_scale_factor;

	Point centroid;
	Size original;
	Size padded;
	bool enableScale;
};

struct Params
{
	double padding;
	double output_sigma_factor;
	double scale_sigma_factor;
	double lambda;
	double learning_rate;
	int number_scales;
	double scale_step;
	int scale_model_max_area;

	Params()
	{
		padding = 1.5;
		output_sigma_factor = 1.0 / 16;
		scale_sigma_factor = 1.0 / 4;
		lambda = 1e-2;
		learning_rate = 0.025;
		number_scales = 33;
		scale_step = 1.02;
		scale_model_max_area = 512;
	}

};
#endif