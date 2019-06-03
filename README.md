# ubit\_uTensor\_demo

Yotta build repository for a CNN to be deployed on the Microbit. This project uses uTensor-cli to compile the Tensorflow model into c++ files, and uses the uTensor kernels for execution. The CNN was found using NAS, and this work has been published to [arxiv](https://arxiv.org/abs/1905.12107).

## Instructions

This project was built in a Docker container. Make sure you have docker installed. I recommend just pulling the image I created for this and running everything in there.

```
docker pull patrickthomashansen/yotta:initial
docker run -ti -v LOCAL_PROJECT_DIRECTORY:/home/ patrickthomashansen/yotta:initial bash
cd /home
git pull https://github.com/patrickthomashansen/ubit_uTensor_demo.git
cd ubit_uTensor_demo/
yotta target bbc-microbit-classic-gcc
yotta build
```
