// The plugin base file needs to get put into our path Gecode so that it can be found 
#include <iostream>

class Square : public Gecode::FlatZinc::PluginBase {
public:
  Square() : PluginBase("Implementation of Square function") {};
  void run(std::vector<int>& in, std::vector<int>& out) { 
    for(int i=0; i < in.size(); i++){
      out[i] = in[i] * in[i];
    }
  };
};

// return void pointer or hide pluginbase tytpe
// don't need base class
// just return a void pointer
// struct PluginBase
// 
extern "C" Gecode::FlatZinc::PluginBase* plugin_create() {
  return new Square;
}

// plugin destroy takes a void pointer as an arg, cast it into base type using reinterpret cast from void pointer, do delete
extern "C" void plugin_destroy(Gecode::FlatZinc::PluginBase* square) {
  delete square;
}

// This is the interface that we will expect from the consumer
// Gets the void pointer plugin as first arg, and inside cast it into the class type
extern "C" void plugin_run(int* in, int in_length, int* out, int out_length) {
  // Can use cpp here
}
// position has to be the position that the number was when it was passed in
// example input: [1,1,1,3,3,3,2]
// [1,1,1,2,3,3,3]
// 2 is median, but we output 2 + 7 = 9
// other sol
// struct pluginbase
// return pluginbase*
