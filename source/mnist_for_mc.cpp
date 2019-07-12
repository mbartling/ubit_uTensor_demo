// Auto generated by utensor-cli

#include "uTensor/core/context.hpp"
#include "ubit-utensor-demo/mnist_for_mc_weight.hpp"
#include "uTensor/ops/MatrixOps.hpp"
#include "uTensor/ops/MathOps.hpp"
#include "uTensor/core/tensor.hpp"
#include "uTensor/ops/ArrayOps.hpp"
#include "uTensor/ops/NnOps.hpp"
#include "mnist_for_mc.hpp"


void get_mnist_for_mc_ctx(Context& ctx, Tensor* input_0) {

{ // add tensor for placeholders
    ctx.add(input_0, sref_Placeholder_0, 2);
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_mul_eightbit_Placeholder__port__0_reshape_dims_0), 
            sref_mul_eightbit_Placeholder__port__0_reshape_dims_0, 
            1);
}
{
    ctx.add(new RamTensor<float>(), sref_mul_eightbit_Placeholder__port__0_reshape_0, 2);
    ctx.push(new ReshapeOp(), 
             { sref_Placeholder_0, sref_mul_eightbit_Placeholder__port__0_reshape_dims_0 },
             { sref_mul_eightbit_Placeholder__port__0_reshape_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_mul_eightbit_Placeholder__port__0_reduction_dims_0), 
            sref_mul_eightbit_Placeholder__port__0_reduction_dims_0, 
            2);
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_mul_eightbit_Placeholder__port__0_min_0, 1);
    ctx.push(new MinOp(), 
             { sref_mul_eightbit_Placeholder__port__0_reshape_0, sref_mul_eightbit_Placeholder__port__0_reduction_dims_0 },
             { sref_mul_eightbit_Placeholder__port__0_min_0 });
    ctx.eval();
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_mul_eightbit_Placeholder__port__0_max_0, 1);
    ctx.push(new MaxOp(), 
             { sref_mul_eightbit_Placeholder__port__0_reshape_0, sref_mul_eightbit_Placeholder__port__0_reduction_dims_0 },
             { sref_mul_eightbit_Placeholder__port__0_max_0 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_mul_eightbit_Placeholder__port__0_quantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_Placeholder__port__0_quantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_Placeholder__port__0_quantize_2, 1);
    ctx.push(new QuantizeV2Op(),
             {  sref_Placeholder_0,  sref_mul_eightbit_Placeholder__port__0_min_0, sref_mul_eightbit_Placeholder__port__0_max_0 },
             {  sref_mul_eightbit_Placeholder__port__0_quantize_0,  sref_mul_eightbit_Placeholder__port__0_quantize_1, sref_mul_eightbit_Placeholder__port__0_quantize_2 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<float>({1}, inline_sref_mul_y_0), 
            sref_mul_y_0, 
            2);
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_mul_eightbit_mul_y__port__0_reshape_dims_0), 
            sref_mul_eightbit_mul_y__port__0_reshape_dims_0, 
            1);
}
{
    ctx.add(new RamTensor<float>(), sref_mul_eightbit_mul_y__port__0_reshape_0, 2);
    ctx.push(new ReshapeOp(), 
             { sref_mul_y_0, sref_mul_eightbit_mul_y__port__0_reshape_dims_0 },
             { sref_mul_eightbit_mul_y__port__0_reshape_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_mul_eightbit_mul_y__port__0_reduction_dims_0), 
            sref_mul_eightbit_mul_y__port__0_reduction_dims_0, 
            2);
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_mul_eightbit_mul_y__port__0_min_0, 1);
    ctx.push(new MinOp(), 
             { sref_mul_eightbit_mul_y__port__0_reshape_0, sref_mul_eightbit_mul_y__port__0_reduction_dims_0 },
             { sref_mul_eightbit_mul_y__port__0_min_0 });
    ctx.eval();
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_mul_eightbit_mul_y__port__0_max_0, 1);
    ctx.push(new MaxOp(), 
             { sref_mul_eightbit_mul_y__port__0_reshape_0, sref_mul_eightbit_mul_y__port__0_reduction_dims_0 },
             { sref_mul_eightbit_mul_y__port__0_max_0 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_mul_eightbit_mul_y__port__0_quantize_0, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_mul_y__port__0_quantize_1, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_mul_y__port__0_quantize_2, 2);
    ctx.push(new QuantizeV2Op(),
             {  sref_mul_y_0,  sref_mul_eightbit_mul_y__port__0_min_0, sref_mul_eightbit_mul_y__port__0_max_0 },
             {  sref_mul_eightbit_mul_y__port__0_quantize_0,  sref_mul_eightbit_mul_y__port__0_quantize_1, sref_mul_eightbit_mul_y__port__0_quantize_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<int>(), sref_mul_eightbit_0, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_1, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_2, 2);
    ctx.push(new QuantizedMulOp<uint8_t, uint8_t, int>(), 
             { sref_mul_eightbit_Placeholder__port__0_quantize_0, sref_mul_eightbit_Placeholder__port__0_quantize_1, sref_mul_eightbit_Placeholder__port__0_quantize_2, sref_mul_eightbit_mul_y__port__0_quantize_0, sref_mul_eightbit_mul_y__port__0_quantize_1,  sref_mul_eightbit_mul_y__port__0_quantize_2 },
             { sref_mul_eightbit_0, sref_mul_eightbit_1,  sref_mul_eightbit_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_requant_range_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_requant_range_1, 1);
    ctx.push(new Requantization_RangeOp(),
             { sref_mul_eightbit_0, sref_mul_eightbit_1, sref_mul_eightbit_2 },
             { sref_mul_eightbit_requant_range_0, sref_mul_eightbit_requant_range_1 });
    ctx.eval();
}
{   
    ctx.add(new RamTensor<uint8_t>(), sref_mul_eightbit_requantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_requantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_eightbit_requantize_2, 1);
    ctx.push(new RequantizeOp(),
             { sref_mul_eightbit_0, sref_mul_eightbit_1, sref_mul_eightbit_2, sref_mul_eightbit_requant_range_0, sref_mul_eightbit_requant_range_1 },
             { sref_mul_eightbit_requantize_0, sref_mul_eightbit_requantize_1, sref_mul_eightbit_requantize_2 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<float>({5,5,1,9}, inline_sref_stochastic_conv2_mu_0), 
            sref_stochastic_conv2_mu_0, 
            2);
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_dims_0), 
            sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_dims_0, 
            1);
}
{
    ctx.add(new RamTensor<float>(), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_0, 2);
    ctx.push(new ReshapeOp(), 
             { sref_stochastic_conv2_mu_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_dims_0 },
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reduction_dims_0), 
            sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reduction_dims_0, 
            2);
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_min_0, 1);
    ctx.push(new MinOp(), 
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reduction_dims_0 },
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_min_0 });
    ctx.eval();
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_max_0, 1);
    ctx.push(new MaxOp(), 
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reshape_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_reduction_dims_0 },
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_max_0 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_2, 1);
    ctx.push(new QuantizeV2Op(),
             {  sref_stochastic_conv2_mu_0,  sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_min_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_max_0 },
             {  sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_0,  sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_1, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_0);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_2);
    ctx.push(new QuantizedFusedConvMaxpoolOp<uint8_t, uint8_t, uint8_t>({ 1, 1, 1, 1 }, { 1, 2, 2, 1 },VALID),
             { sref_mul_eightbit_requantize_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_0, sref_mul_eightbit_requantize_1, sref_mul_eightbit_requantize_2, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_1, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_stochastic_conv2_mu__port__0_quantize_2 },
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_1, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_2 });
    ctx.eval();
}

{
    ctx.add(new RamTensor<uint8_t>(), sref_Relu_eightbit_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_Relu_eightbit_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_Relu_eightbit_2, 1);
    ctx.push(new QuantizedReluOp<uint8_t, float, uint8_t>(), 
             { sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_0, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_1, sref_stochastic_conv2d__channel__pruning_Conv2D_eightbit_max_pooling2d_MaxPool_eightbit_2 },
             { sref_Relu_eightbit_0, sref_Relu_eightbit_1, sref_Relu_eightbit_2 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({2}, inline_sref_Reshape_1_shape_0), 
            sref_Reshape_1_shape_0, 
            1);
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_Reshape_1_eightbit_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_Reshape_1_eightbit_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_Reshape_1_eightbit_2, 1);
    ctx.push(new QuantizedReshapeOp(),
              { sref_Relu_eightbit_0, sref_Reshape_1_shape_0, sref_Relu_eightbit_1, sref_Relu_eightbit_2 },
              { sref_Reshape_1_eightbit_0, sref_Reshape_1_eightbit_1, sref_Reshape_1_eightbit_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<float>(), sref_Reshape_1_0, 1);
    ctx.push(new DequantizeOp(), 
             { sref_Reshape_1_eightbit_0, sref_Reshape_1_eightbit_1, sref_Reshape_1_eightbit_2 },
             { sref_Reshape_1_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({119}, inline_sref_GatherV2_indices_0), 
            sref_GatherV2_indices_0, 
            1);
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_GatherV2_axis_0), 
            sref_GatherV2_axis_0, 
            1);
}
{
    ctx.add(new RamTensor<float>(), sref_GatherV2_0, 2);
    ctx.push(new GatherOp<float>(),
             { sref_Reshape_1_0, sref_GatherV2_indices_0, sref_GatherV2_axis_0 }, 
             { sref_GatherV2_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_dims_0), 
            sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_dims_0, 
            1);
}
{
    ctx.add(new RamTensor<float>(), sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_0, 2);
    ctx.push(new ReshapeOp(), 
             { sref_GatherV2_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_dims_0 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_0 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<int>({1}, inline_sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reduction_dims_0), 
            sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reduction_dims_0, 
            2);
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_min_0, 1);
    ctx.push(new MinOp(), 
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reduction_dims_0 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_min_0 });
    ctx.eval();
}
{   
    RamTensor<float>* out_tensor;
    out_tensor = new RamTensor<float>({ 1 });
    ctx.add(out_tensor, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_max_0, 1);
    ctx.push(new MaxOp(), 
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reshape_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_reduction_dims_0 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_max_0 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<uint8_t>(), sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_2, 1);
    ctx.push(new QuantizeV2Op(),
             {  sref_GatherV2_0,  sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_min_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_max_0 },
             {  sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_0,  sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_2 });
    ctx.eval();
}
{    
    ctx.add(new BinaryTensor<uint8_t>({119,10}, inline_sref_stochastic_dense_mu_quantized_const_0), 
            sref_stochastic_dense_mu_quantized_const_0, 
            1);
}
{    
    ctx.add(new BinaryTensor<float>({1}, inline_sref_stochastic_dense_mu_quantized_min_0), 
            sref_stochastic_dense_mu_quantized_min_0, 
            1);
}
{    
    ctx.add(new BinaryTensor<float>({1}, inline_sref_stochastic_dense_mu_quantized_max_0), 
            sref_stochastic_dense_mu_quantized_max_0, 
            1);
}
{
    ctx.add(new RamTensor<int>(), sref_stochastic_dense__channel__pruning_MatMul_eightbit_0, 2);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_1, 2);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_2, 2);
    ctx.push(new QntMatMulOp<uint8_t, uint8_t, int>(), 
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_GatherV2__port__0_quantize_2, sref_stochastic_dense_mu_quantized_const_0, sref_stochastic_dense_mu_quantized_min_0,  sref_stochastic_dense_mu_quantized_max_0 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_1,  sref_stochastic_dense__channel__pruning_MatMul_eightbit_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_1, 1);
    ctx.push(new Requantization_RangeOp(),
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_2 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_1 });
    ctx.eval();
}
{   
    ctx.add(new RamTensor<uint8_t>(), sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_2, 1);
    ctx.push(new RequantizeOp(),
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_2, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requant_range_1 },
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<int>(), sref_mul_6_eightbit_0, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_1, 2);
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_2, 2);
    ctx.push(new QuantizedMulOp<uint8_t, uint8_t, int>(), 
             { sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_0, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_1, sref_stochastic_dense__channel__pruning_MatMul_eightbit_requantize_2, sref_mul_eightbit_mul_y__port__0_quantize_0, sref_mul_eightbit_mul_y__port__0_quantize_1,  sref_mul_eightbit_mul_y__port__0_quantize_2 },
             { sref_mul_6_eightbit_0, sref_mul_6_eightbit_1,  sref_mul_6_eightbit_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_requant_range_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_requant_range_1, 1);
    ctx.push(new Requantization_RangeOp(),
             { sref_mul_6_eightbit_0, sref_mul_6_eightbit_1, sref_mul_6_eightbit_2 },
             { sref_mul_6_eightbit_requant_range_0, sref_mul_6_eightbit_requant_range_1 });
    ctx.eval();
}
{   
    ctx.add(new RamTensor<uint8_t>(), sref_mul_6_eightbit_requantize_0, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_requantize_1, 1);
    ctx.add(new RamTensor<float>({1}), sref_mul_6_eightbit_requantize_2, 1);
    ctx.push(new RequantizeOp(),
             { sref_mul_6_eightbit_0, sref_mul_6_eightbit_1, sref_mul_6_eightbit_2, sref_mul_6_eightbit_requant_range_0, sref_mul_6_eightbit_requant_range_1 },
             { sref_mul_6_eightbit_requantize_0, sref_mul_6_eightbit_requantize_1, sref_mul_6_eightbit_requantize_2 });
    ctx.eval();
}
{
    ctx.add(new RamTensor<float>(), sref_mul_6_0);
    ctx.push(new DequantizeOp(), 
             { sref_mul_6_eightbit_requantize_0, sref_mul_6_eightbit_requantize_1, sref_mul_6_eightbit_requantize_2 },
             { sref_mul_6_0 });
}
}
