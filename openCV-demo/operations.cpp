#include "operations.h"
#include "operations/cannyedges.h"
#include "operations/morphology.h"
#include "operations/cvtcolor.h"



using namespace cv;

// Public
Operations::Operations():
    operationList((QStringList()
    << "Morphology"
    << "CvtColor"
    << "Canny Edges"
    << "huy")){}

Operations::~Operations(){
    std::cout << "Operations destructor" << std::endl;
    delete selectedOperation;
}

QWidget* Operations::getLayouts(const QString* operation){

    QWidget* returnLayout;

    //look for operation
   if (*operation == "Morphology"){
       selectedOperation = new Morphology();
       returnLayout = selectedOperation->getLayout(this);

   }
   else if (*operation == "CvtColor"){
       selectedOperation = new CvtColor();
       returnLayout = selectedOperation->getLayout(this);

   }
   else if (*operation == "Canny Edges"){
       selectedOperation = new CannyEdges();
       returnLayout = selectedOperation->getLayout(this);

   }
   else{
       std::cout << "operation doesn't exist" << std::endl;
       return NULL;
    }

    //set layout name
    returnLayout->setObjectName(childName);

    return returnLayout;
}

cv::Mat Operations::switchOperations(cv::Mat image) const{
    cv::Mat ret = selectedOperation->processImage(image);
    return (ret);
}

//Slots
void Operations::onSignalReceived(){
    emit performOperationEvent();
}

