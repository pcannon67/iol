/* 
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author: Ugo Pattacini
 * email:  ugo.pattacini@iit.it
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>

#include <yarp/os/Time.h>
#include <yarp/os/Semaphore.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/RpcServer.h>
#include <yarp/os/RpcClient.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Port.h>
#include <yarp/sig/Image.h>
#include <yarp/sig/Vector.h>

#include <cv.h>

#include "utils.h"
#include "classifierHandling.h"

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;


/**********************************************************/
class Manager : public RFModule
{
protected:
    RpcServer           rpcHuman;
    RpcClient           rpcBlobExtractor;
    RpcClient           rpcClassifier;
    RpcClient           rpcMotor;
    RpcClient           rpcWBD;
    RpcClient           rpcMotorStop;
    RpcClient           rpcMemory;
    StopCmdPort         rxMotorStop;
    PointedLocationPort pointedLoc;
    MemoryReporter      memoryReporter;

    BufferedPort<ImageOf<PixelBgr> > imgIn;
    Port imgOut;
    Port imgRtLocOut;
    Port imgClassifier;

    Speaker speaker;
    Attention attention;
    RtLocalization rtLocalization;
    MemoryUpdater memoryUpdater;
    ClassifiersDataBase db;
    map<string,int> memoryIds;

    ImageOf<PixelBgr> img;
    ImageOf<PixelBgr> imgRtLoc;
    Semaphore mutexResources;
    Semaphore mutexResourcesMemory;
    Semaphore mutexAttention;
    Semaphore mutexMemoryUpdate;
    
    string name;
    string camera;
    string objectToBeKinCalibrated;
    bool scheduleLoadMemory;
    bool enableInterrupt;
    bool actionInterrupted;
    bool skipGazeHoming;

    bool    trackStopGood;
    bool    whatGood;
    CvPoint trackStopLocation;
    CvPoint whatLocation;

    Bottle memoryBlobs;
    Bottle memoryScores;

    friend class Attention;
    friend class RtLocalization;
    friend class MemoryUpdater;
    friend class MemoryReporter;

    int     processHumanCmd(const Bottle &cmd, Bottle &b);
    Bottle  getBlobs();
    CvPoint getBlobCOG(const Bottle &blobs, const int i);
    bool    get3DPosition(const CvPoint &point, Vector &x);
    void    acquireImage(const bool rtlocalization=false);
    void    drawBlobs(const Bottle &blobs, const int i, Bottle *scores=NULL);
    void    loadMemory();
    void    updateClassifierInMemory(Classifier *pClassifier);
    void    updateObjCartPosInMemory(const string &object, const Bottle &blobs, const int i);
    int     findClosestBlob(const Bottle &blobs, const CvPoint &loc);
    Bottle  classify(const Bottle &blobs, const bool rtlocalization=false);
    void    train(const string &object, const Bottle &blobs, const int i);
    void    home();
    void    home(const string &part);
    void    calibTable();
    bool    calibKinStart(const string &object, const string &hand, const int recogBlob);
    void    calibKinStop();
    void    wbdRecalibration();
    void    _motor(const string &cmd, const string &object);
    void    _motor(const string &cmd, const Bottle &blobs, const int i);
    bool    interruptableAction(const string &action, deque<string> *param, const string &object);
    void    point(const string &object);
    void    look(const string &object);
    void    point(const Bottle &blobs, const int i);
    void    look(const Bottle &blobs, const int i);
    int     recognize(const string &object, Bottle &blobs, Classifier **ppClassifier=NULL);
    int     recognize(Bottle &blobs, Bottle &scores, string &object);
    void    execName(const string &object);
    void    execForget(const string &object);
    void    execWhere(const string &object, const Bottle &blobs, const int recogBlob, Classifier *pClassifier);
    void    execWhat(const Bottle &blobs, const int pointedBlob, const Bottle &scores, const string &object);
    void    execExplore(const string &object);
    void    execInterruptableAction(const string &action, const string &object, const int recogBlob);
    void    switchAttention();
    void    doLocalization();
    void    updateMemory();

public:
    void    interruptMotor();
    void    reinstateMotor(const bool saySorry=true);
    bool    configure(ResourceFinder &rf);
    bool    interruptModule();
    bool    close();
    bool    updateModule();
    double  getPeriod();    
};

#endif

