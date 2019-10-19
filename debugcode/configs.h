#ifndef DATATYPECONFIG
#define DATATYPECONFIG

#define NUMBER_OF_LUT_ETRIES_SIGMOID_1 256
#define NUMBER_OF_LUT_ETRIES_TANH_1 256

#define NUMBER_OF_DENSE1_DIM_1 64
#define NUMBER_OF_DENSE1_DIM_2 16
#define NUMBER_OF_DENSE2_DIM_1 16
#define NUMBER_OF_DENSE2_DIM_2 1

typedef double dataType;
typedef int intType;
typedef ap_uint<BiasWidth_gi> biasDataType;


typedef t_fixed_wgi_ih t_fixed_wgi;
typedef t_fixed_wgf_ih t_fixed_wgf;
typedef t_fixed_wgo_ih t_fixed_wgo;
typedef t_fixed_wci_ih t_fixed_wci;
typedef t_fixed_bgi_ih t_fixed_bgi;
typedef t_fixed_bgf_ih t_fixed_bgf;
typedef t_fixed_bgo_ih t_fixed_bgo;
typedef t_fixed_bci_ih t_fixed_bci;

typedef ap_fixed<16 ,8, AP_RND_ZERO, AP_WRAP> t_fixed_sum_wgi;
typedef t_fixed_sum_wgi t_fixed_mul_wgi;

typedef ap_fixed<16 ,8, AP_RND_ZERO, AP_WRAP> t_fixed_sum_wgf;
typedef t_fixed_sum_wgf t_fixed_mul_wgf;

typedef ap_fixed<16 ,8, AP_RND_ZERO, AP_WRAP> t_fixed_sum_wgo;
typedef t_fixed_sum_wgo t_fixed_mul_wgo;

typedef ap_fixed<16 ,8, AP_RND_ZERO, AP_WRAP> t_fixed_sum_wci;

typedef t_fixed_sum_wci t_fixed_mul_wci;

// Hidden Layer
typedef ap_fixed<16 ,8, AP_RND_CONV, AP_SAT> t_fixed_state;
typedef t_fixed_state t_fixed_ci_gi_mul;

typedef ap_fixed<16 ,8, AP_RND_CONV, AP_SAT> t_fixed_gix_sum;
typedef ap_fixed<16 ,8, AP_RND_CONV, AP_SAT> t_fixed_gfx_sum;
typedef ap_fixed<16 ,8, AP_RND_CONV, AP_SAT> t_fixed_gox_sum;

typedef ap_ufixed<8 ,1, AP_RND_ZERO, AP_WRAP> t_fixed_sigma_o;
typedef ap_fixed<8 ,2, AP_RND_ZERO, AP_WRAP> t_fixed_tanh_o;

// LUT
typedef ap_ufixed<10 ,10, AP_RND_ZERO, AP_WRAP> t_fixed_lut_xi;

typedef ap_fixed<8 ,4, AP_RND_ZERO, AP_WRAP>   t_fixed_lut_sigmoid_limit;
typedef ap_ufixed<8 ,6, AP_RND_ZERO, AP_WRAP>  t_fixed_lut_sigmoid_recip_step;

typedef ap_fixed<8 ,3, AP_RND_ZERO, AP_WRAP>   t_fixed_lut_tanh_limit;
typedef ap_ufixed<8 ,7, AP_RND_ZERO, AP_WRAP>  t_fixed_lut_tanh_recip_step;

typedef ap_fixed<16 ,6, AP_RND_ZERO, AP_WRAP> t_fixed_lut_exp_limit;
typedef ap_fixed<16 ,7, AP_RND_ZERO, AP_WRAP> t_fixed_lut_exp_input_1;
typedef ap_ufixed<8 ,5, AP_RND_ZERO, AP_WRAP> t_fixed_lut_exp_recip_step;

// Dot product
typedef ap_fixed<OUTPUTACTIVATIONOUTPUTLAYERWIDTH,8, AP_RND_CONV, AP_WRAP> t_fixed_sum_fc;
typedef ap_fixed<PIXELWIDTH ,1, AP_RND_ZERO, AP_WRAP> t_fixed_image;
typedef ap_fixed<OUTPUTACTIVATIONHIDDENLAYERWIDTH ,1, AP_RND_CONV, AP_SAT> t_fixed_recurrent;

typedef t_fixed_sum_fc t_fixed_mul_fc;

// DATA STRUCTURES
struct maxx
{
	t_fixed_sum_fc value;
	ap_uint<NUMBER_OF_CLASSES_TYPEWIDTH> label;
};

static t_fixed_sigma_o lut_sigmoid_1[NUMBER_OF_LUT_ETRIES_SIGMOID_1] = {
0,0,0,0,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,
0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.015625,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,0.03125,
0.046875,0.046875,0.046875,0.046875,0.046875,0.046875,0.046875,0.046875,0.046875,0.0625,0.0625,0.0625,0.0625,0.0625,0.0625,0.0625,0.078125,0.078125,0.078125,0.078125,0.078125,0.078125,
0.09375,0.09375,0.09375,0.09375,0.109375,0.109375,0.109375,0.109375,0.109375,0.125,0.125,0.125,0.140625,0.140625,0.140625,0.15625,0.15625,0.15625,0.171875,0.171875,0.171875,0.1875,0.1875,
0.1875,0.203125,0.203125,0.21875,0.21875,0.21875,0.234375,0.234375,0.25,0.25,0.265625,0.265625,0.28125,0.28125,0.296875,0.296875,0.3125,0.3125,0.328125,0.328125,0.34375,0.359375,0.359375,
0.375,0.375,0.390625,0.40625,0.40625,0.421875,0.421875,0.4375,0.453125,0.453125,0.46875,0.46875,0.484375,0.5,0.5,0.515625,0.53125,0.53125,0.546875,0.546875,0.5625,0.578125,0.578125,0.59375,
0.59375,0.609375,0.625,0.625,0.640625,0.640625,0.65625,0.671875,0.671875,0.6875,0.6875,0.703125,0.703125,0.71875,0.71875,0.734375,0.734375,0.75,0.75,0.765625,0.765625,0.78125,0.78125,0.78125,
0.796875,0.796875,0.8125,0.8125,0.8125,0.828125,0.828125,0.828125,0.84375,0.84375,0.84375,0.859375,0.859375,0.859375,0.875,0.875,0.875,0.890625,0.890625,0.890625,0.890625,0.890625,0.90625,
0.90625,0.90625,0.90625,0.921875,0.921875,0.921875,0.921875,0.921875,0.921875,0.9375,0.9375,0.9375,0.9375,0.9375,0.9375,0.9375,0.953125,0.953125,0.953125,0.953125,0.953125,0.953125,0.953125,
0.953125,0.953125,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,
0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,1,1,1,1};

static t_fixed_tanh_o lut_tanh_1[NUMBER_OF_LUT_ETRIES_TANH_1] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,
-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.984375,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,-0.96875,
-0.96875,-0.953125,-0.953125,-0.953125,-0.953125,-0.953125,-0.953125,-0.953125,-0.9375,-0.9375,-0.9375,-0.9375,-0.9375,-0.9375,-0.921875,-0.921875,-0.921875,-0.921875,-0.90625,-0.90625,
-0.90625,-0.90625,-0.890625,-0.890625,-0.890625,-0.875,-0.875,-0.875,-0.859375,-0.859375,-0.84375,-0.84375,-0.84375,-0.828125,-0.828125,-0.8125,-0.8125,-0.796875,-0.796875,-0.78125,
-0.765625,-0.765625,-0.75,-0.734375,-0.734375,-0.71875,-0.703125,-0.703125,-0.6875,-0.671875,-0.65625,-0.640625,-0.625,-0.609375,-0.59375,-0.578125,-0.5625,-0.546875,-0.53125,-0.515625,
-0.5,-0.484375,-0.46875,-0.453125,-0.421875,-0.40625,-0.390625,-0.375,-0.34375,-0.328125,-0.3125,-0.28125,-0.265625,-0.234375,-0.21875,-0.203125,-0.171875,-0.15625,-0.125,-0.109375,
-0.078125,-0.0625,-0.03125,-0.015625,0.015625,0.03125,0.0625,0.078125,0.109375,0.125,0.15625,0.171875,0.203125,0.21875,0.234375,0.265625,0.28125,0.3125,0.328125,0.34375,0.375,0.390625,
0.40625,0.421875,0.453125,0.46875,0.484375,0.5,0.515625,0.53125,0.546875,0.5625,0.578125,0.59375,0.609375,0.625,0.640625,0.65625,0.671875,0.6875,0.703125,0.703125,0.71875,0.734375,
0.734375,0.75,0.765625,0.765625,0.78125,0.796875,0.796875,0.8125,0.8125,0.828125,0.828125,0.84375,0.84375,0.84375,0.859375,0.859375,0.875,0.875,0.875,0.890625,0.890625,0.890625,0.90625,
0.90625,0.90625,0.90625,0.921875,0.921875,0.921875,0.921875,0.9375,0.9375,0.9375,0.9375,0.9375,0.9375,0.953125,0.953125,0.953125,0.953125,0.953125,0.953125,0.953125,0.96875,0.96875,
0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.96875,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,
0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,0.984375,1,1,1,1,1,1,1,1,1,1};
#endif