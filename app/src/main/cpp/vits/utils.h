#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <math.h>
#include <numeric>
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <cstdio>

// ncnn
#include "layer.h"
#include "net.h"
#include "cpu.h"
#include "benchmark.h"

// fft
#include "../fftpack/fftpack.h"
#include <complex>

#define PI 3.14159265358979323846
#define MAX_MEM_BLOCK 262144

using namespace ncnn;

Mat as_strides(const Mat& x, const int h, const int w, Option& opt); // dummy array

Mat cumsum(const Mat& blob, const Option& opt);

Mat ceil(const Mat& m, const Option& opt);

Mat concat(const Mat& m1, const Mat& m2, const Option& opt); // concat for row

Mat div(const Mat& m, float value, const Option& opt);

void drop(Mat& m, float scale, const Option& opt);

Mat expanddims(const Mat& m);

Mat expand(const Mat& m, int w, int h, const Option& opt);

Mat frame(const Mat& x, const int frame_length, const int hop_length, Option& opt);

Mat gather(Mat& blob, Mat& index, const Option& opt);

Mat generate_path(const Mat& duration, const Mat mask, const Option& opt);

Mat hanning_window(const int n, Option& opt);

std::string join_path(const std::string& folder, const std::string& file);

Mat matplus(const Mat& m1, const Mat& m2, const Option& opt);

Mat matminus(const Mat& m1, const Mat& m2, const Option& opt);

Mat matdiv(const Mat& m1, const Mat& m2, const Option& opt);

Mat matproduct(const Mat& m1, const Mat& m2, const Option& opt);

Mat matpow(const Mat& m, float value, const Option& opt);

Mat matexp(const Mat& m, const Option& opt);

Mat matsqrt(const Mat& m, const Option& opt);

float matmax(const Mat& m, const Option& opt);

Mat mattranspose(const Mat& m, const Option& opt);

Mat matmul(const Mat& m1, const Mat& m2, const Option& opt);

void mask_fill(Mat& m, const Mat& mask, const char* condition, float condition_value, float value, const Option& opt);

void pretty_print(const ncnn::Mat& m, const Option& opt, const char* name);

Mat pad(const Mat& blob, int pad_top, int pad_bottom, int pad_left, int pad_right, float pad_value, const Option& opt); // 横向右部填充

Mat product(const Mat& m, float value, const Option& opt);

Mat Plus(const Mat& m, float value, const Option& opt);

Mat reducedims(const Mat& m);

Mat randn(int w, int h, const Option& opt, int c = 0);

std::vector<std::complex<fftpack_real>> rfft1d(const fftpack_real* data, const size_t size, Option& opt);

std::vector<Mat> rfft(const Mat& m, Option& opt); // rfft for dim 0

Mat softmax(const Mat& blob, const Option& opt, int axis=-1); // 按行求softmax

Mat Slice(const Mat &blob, int top, int bottom, int left, int right, int stride_w, int stride_h,
          const Option &opt);

void set_column_value(Mat& blob, int column, float value, const Option& opt);

Mat softplus(const Mat& blob, const Option& opt);

Mat searchsorted(Mat& bin_locations, const Mat& inputs, const Option& opt);

Mat sum(const Mat& m, const Option& opt);

Mat sequence_mask(const Mat& length,  const Option& opt, float max_length_ = 0);

std::vector<Mat> stft(const Mat& y, const int filter_length, const int hop_length,
                      const int win_length, Option& opt); // short time Fourier transform

Mat zeros_like(const Mat& x, const Option& opt);

Mat _get_relative_embeddings(const Mat& relative_embeddings, int length, int window_size, const Option& opt);

Mat _matmul_with_relative_keys(const Mat& x, const Mat& y, const Option& opt);

Mat _relative_position_to_absolute_position(const Mat& x, const Option& opt);

Mat _absolute_position_to_relative_position(const Mat& x, const Option& opt);

Mat _matmul_with_relative_values(const Mat& x, const Mat& y, const Option& opt);

#endif