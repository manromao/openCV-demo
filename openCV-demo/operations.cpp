#include "operations.h"
#include "operations/morphology.h"
#include "operations/cvtcolor.h"



using namespace cv;

Operations::Operations():
    operationList((QStringList()
    << "Morphology"
    << "CvtColor"
    << "huy")){}

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
   else{
       std::cout << "operation doesn't exist" << std::endl;
       return NULL;
    }


    //set layout name
    returnLayout->setObjectName(childName);

    return returnLayout;
}


void Operations::switchOperations(const QString operation, cv::Mat image) const{
        selectedOperation->processImage(image);
}

void Operations::onSignalReceived(){
    emit performOperationEvent();
}

