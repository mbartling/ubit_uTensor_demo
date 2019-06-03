# ubit\_uTensor\_demo

Yotta build repository for a CNN to be deployed on the Microbit. This project uses uTensor-cli to compile the Tensorflow model into c++ files, and uses the uTensor kernels for execution. The CNN was found using NAS, and this work has been published to [arxiv](https://arxiv.org/abs/1905.12107).

## Instructions

This project was built in a Docker container. Make sure you have docker installed. I recommend just pulling the image I created for this and running everything in there. I included both the protobuf file for the CNN model, as well as the output c++ files from utensor-cli. These instructions will just assume you just use the pre-existing files for simplicity.

```
docker pull patrickthomashansen/yotta:initial
docker run -ti -v LOCAL_PROJECT_DIRECTORY:/home/ patrickthomashansen/yotta:initial bash
cd /home
yotta target bbc-microbit-classic-gcc
yotta build
```

Then copy the file `LOCAL_PROJECT_DIRECTORY/ubit_uYensor_demo/build/bbc-microbit-classic-gcc/source/ubit-utensor-demo-combined.hex` onto your microbit to run inference. If it succeeds, it will display a the predicted class on its LED display. Otherwise, the LED display will scroll with a sad face and error code.
