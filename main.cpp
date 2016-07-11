#include <cv.h>
#include <highgui.h>

using namespace cv;

const int countTest = 10;
const long double isColor = 0.95;

//check it's grayscale mode or color
bool isNotGrayScale(const Mat &image) {

    RNG rngCV(getTickCount());
    long double probably = 1.0;

    for (int i = 0; i < countTest; ++i) {
        int x = rngCV.uniform(0, image.rows);
        int y = rngCV.uniform(0, image.cols);

        int b = image.at<Vec3b>(x, y)[0];
        int g = image.at<Vec3b>(x, y)[1];
        int r = image.at<Vec3b>(x, y)[2];

        long double mid = (b + g + r) / 3.0;
        probably *= 1 - (abs(mid - r) + abs(mid - g) + abs(mid - b)) / 768.0;

        if (probably < isColor) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {

        printf("write path to video");
        return 0;
    }

    Mat frame;
    VideoCapture cap(argv[1]);
    int totalframe = cap.get(CV_CAP_PROP_FRAME_COUNT);

    if (!totalframe) {
        printf("error path");
        return 0;
    }

    while (totalframe > 0) {
        cap >> frame;

        if (isNotGrayScale(frame)) {

            printf("color");
            return 0;
        }

        totalframe--;
    }

    printf("black-white");

    return 0;
}