    #include <opencv2/opencv.hpp> 
    int main() 
    { 
       cv::Mat img = cv::imread("file.jpg"); 
       int darray[10000][10000]; 
       for(int i=0;i<img.cols;i++) 
          { 
             for(int j=0;j<img.rows;j++) 
                { 
                   darray[i][j]=img.at<int>(i,j); 
                } 
          } 
    } 