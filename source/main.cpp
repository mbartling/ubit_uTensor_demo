#include "ubit-utensor-demo/mnist_under2k_wm_for_uTensor_folded_input_downsampling.hpp"  //gernerated model file
#include "ubit-utensor-demo/mnist_under2k_wm_for_uTensor_folded_input_downsampling_weight.hpp"  //gernerated model file
#include "ubit-utensor-demo/input_data.h"  //contains the first sample taken from the MNIST test set

#include "uTensor/core/context.hpp"
#include "uTensor/core/tensor.hpp"  //useful tensor classes
#include "mbed.h"

DigitalOut col0(P0_4, 0);
DigitalOut myled(P0_13);

static Context ctx;  //creating the context class, the stage where inferences take place
Timer t;

int main(void) {
  //Context ctx;  //creating the context class, the stage where inferences take place 
  //wrapping the input data in a tensor class
  printf("Starting\n");
  Tensor* input_x = new WrappedRamTensor<float>({1, 9, 9}, (float*) input_data);
  //Tensor* input_x = new WrappedRamTensor<float>({1, 28, 28}, (float*) input_data);
	t.start();
  get_mnist_under2k_wm_for_uTensor_folded_input_downsampling_ctx(ctx, input_x);
  S_TENSOR pred_tensor = ctx.get(sref_model_stochastic_dense__channel__pruning_add_0);  // getting a reference to the output tensor
  ctx.eval(); //trigger the inference
  t.stop();
  printf("The time taken was %f seconds (%d us)\n", t.read(), t.read_us()); 

  //int pred_label = *(pred_tensor->read<int>(0, 0));  //getting the result back
  const float* pred_label = pred_tensor->read<float>(0, 0);  //getting the result back
	const float reference[] = {0.47058824, 0., 0., 0.28235295, 0., 0., 0., 0., 1.1058824, 0.8};
  printf("Predicted Label: %f\n", pred_label[0]);
  float sum = 0;
  for(int i = 0; i < 9; i++){
      printf("Pred %d: %f\n", i, pred_label[i]);
    if(reference[i] != 0)
      sum += (reference[i] - pred_label[i])/reference[i];
  }
    sum  *= 100.0/9.0;
    printf("Mean percent error %f\n", sum);
  
  // blink when prediction is complete
  while(1) {
    myled = 1;
    wait(0.2);
    myled = 0;
    wait(0.2);
  }
}
