#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

int main() {
    string filename;
    cin >> filename; // ����ڷκ��� ���ϸ� �Է¹���

    // �̹��� �ҷ����� (�׷��̽�����)    
    Mat img = imread(filename, IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return -1;
    }

    // �ִ밪 ��� ���ϱ�
    double minVal, maxVal;
    minMaxLoc(img, &minVal, &maxVal);

    // ��� �ִ� ��� (���������� ���)
    cout << static_cast<int>(maxVal) << endl;

    return 0;
}
