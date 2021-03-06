#ifndef DATACAM_H
#define DATACAM_H


#include "vector"

#include "image.h"

#include "videocam.h"


class DataSetCam : public VideoCam
{
    bool error=true;

    bool frm_pending=false;

    Image <RGB24Pixel> buffer;
    double time=0;

    std::string strDir;

    std::vector <std::string> img_list;
    std::vector <double> img_time;
    u_int img_inx=0;


public:
    DataSetCam(const char *DataSetDir,const char *DataSetFile,Size2D frame_size,const char *log_name=NULL);
    ~DataSetCam();
    int WaitFrame(bool drop_frames=true) override;
    int LoadImage(const std::string &i_name);
    int GrabFrame(RGB24Pixel *data, double &tstamp, bool drop_frames=true) override;
    RGB24Pixel* GrabBuffer(double &tstamp,bool drop_frames=true) override;
    int ReleaseBuffer() override ;
    const bool & Error() override{return error;}
};

#endif // DATACAM_H
