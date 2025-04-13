#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

int main() {
    string filename;
    cin >> filename; // 사용자로부터 파일명 입력받음

    // 이미지 불러오기 (그레이스케일)    
    Mat img = imread(filename, IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }

    // 최대값 밝기 구하기
    double minVal, maxVal;
    minMaxLoc(img, &minVal, &maxVal);

    // 밝기 최댓값 출력 (정수형으로 출력)
    cout << static_cast<int>(maxVal) << endl;

    return 0;
}
