#include "operations.h"
#include "operations/cannyedges.h"
#include "operations/morphology.h"
#include "operations/cvtcolor.h"
#include "operations/thresholdgray.h"
#include "operations/houghlinesPdetector.h"


using namespace cv;

// Public
Operations::Operations():
    operationList((QStringList()
    << "Morphology"
    << "CvtColor"
    << "Canny Edges"
    << "Threshold(GRAY)"
    << "HoughLines"
    )){

    selectedOperation = new Function(this);
}

Operations::~Operations(){
    std::cout << "Operations destructor" << std::endl;
    selectedOperation->deleteLater();
}

QWidget* Operations::getLayouts(const QString* operation){

    QWidget* returnLayout;

    delete (selectedOperation);
    //look for operation
   if (*operation == "Morphology"){       
       selectedOperation = new Morphology();
   }

   else if (*operation == "CvtColor"){
       selectedOperation = new CvtColor();
   }

   else if (*operation == "Canny Edges"){
       selectedOperation = new CannyEdges();
   }

   else if (*operation == "Threshold(GRAY)"){
       selectedOperation = new ThresholdGray();
   }

   else if (*operation == "HoughLines"){
       selectedOperation = new HoughLinesDetector();
   }

   else{
       std::cout << "operation doesn't exist" << std::endl;
   }

    returnLayout = selectedOperation->getLayout(this);

    //set layout name(Used to delete it later on)
    returnLayout->setObjectName(childName);

    return returnLayout;
}

cv::Mat Operations::switchOperations(cv::Mat image) const{
    cv::Mat ret = selectedOperation->processImage(image);
    selectedOperation->processImage(image);
    return (ret);
}

//Slots
void Operations::onWidgetChanged(){
    emit performOperationEvent();
}

