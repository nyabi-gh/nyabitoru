#include <onnxruntime_cxx_api.h>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "사용 방법: " << argv[0] << " <model.onnx> <image.jpg>\n";

        return 1;
    }
    
    return 0;
}