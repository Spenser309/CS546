/*
 ============================================================================
 Name        : opencv-intro.c
 Author      : Spenser Gilliland
 Version     :
 Copyright   : GPLv3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

void mouseHandler(int event, int x, int y, int flags, void* param) {
  switch(event){
    case CV_EVENT_LBUTTONDOWN:
      if(flags & CV_EVENT_FLAG_CTRLKEY)
        printf("Left button down with CTRL pressed\n");
      break;
    case CV_EVENT_LBUTTONUP:
      printf("Left button up\n");
      break;
  }
}

int main(int argc, char *argv[]) {
  IplImage* img;
  int height,width,step,channels;
  uchar *data;
  int i,j,k;
  int mouseParam;
  char key;

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  // load an image
  img=cvLoadImage(argv[1], -1);
  if(!img){
    printf("Could not load image file: %s\n",argv[1]);
    exit(0);
  }

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  printf("Processing a %dx%d image with %d channels\n",height,width,channels);

  // create a window
  cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
  cvMoveWindow("mainWin", 0, 0);

  // invert the image
  for(i=0;i<height;i++) for(j=0;j<width;j++) for(k=0;k<channels;k++)
    data[i*step+j*channels+k]=255-data[i*step+j*channels+k];

  // Setup mouse handler
  mouseParam=5;
  cvSetMouseCallback("mainWin", mouseHandler, &mouseParam);
  // show the image
  cvShowImage("mainWin", img );

  // wait for a key
  while(1){
    key=cvWaitKey(10);
    if(key==27) break;

    switch(key){
      case 'h':
        printf("h pressed \n");
        break;
      case 'i':
        printf("i pressed \n");
        break;
    }
  }

  // release the image
  cvReleaseImage(&img );
  return 0;
}
