#include "ubit-utensor-demo/mnist_for_mc.hpp"  //gernerated model file
#include "ubit-utensor-demo/input_data.h"  //contains the first sample taken from the MNIST test set

#include "uTensor/core/context.hpp"
#include "uTensor/core/tensor.hpp"  //useful tensor classes
#include "mbed.h"
#include "MicroBit.h"

MicroBit uBit;

static Context ctx;  //creating the context class, the stage where inferences take place

int main(void) {
  uBit.init();

  //Context ctx;  //creating the context class, the stage where inferences take place 
  //wrapping the input data in a tensor class
  Tensor* input_x = new WrappedRamTensor<float>({1, 784}, (float*) input_data);

  get_mnist_for_mc_ctx(ctx, input_x);  // pass the tensor to the context
  //S_TENSOR pred_tensor = ctx.get("y_pred:0");  // getting a reference to the output tensor
  //ctx.eval(); //trigger the inference

  //int pred_label = *(pred_tensor->read<int>(0, 0));  //getting the result back
  //uBit.display.scroll(pred_label);
  uBit.display.scroll("Hello");

  release_fiber();
}
