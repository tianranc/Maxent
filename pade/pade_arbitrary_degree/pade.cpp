/*****************************************************************************
*
* ALPS Project Applications
*
* Copyright (C) 2013 by Emanuel Gull <egull@umich.edu>
*
* This software is part of the ALPS Applications, published under the ALPS
* Application License; you can use, redistribute it and/or modify it under
* the terms of the license, either version 1 or (at your option) any later
* version.
* 
* You should have received a copy of the ALPS Application License along with
* the ALPS Applications; see the file LICENSE.txt. If not, the license is also
* available from http://alps.comp-phys.org/.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#include "pade.hpp"

int main(int argc, char** argv)
{
  //parse parameters etc
  alps::mcoptions options(argc, argv);
  alps::params parms(options.input_file);
  std::string out_file(boost::lexical_cast<std::string>(parms["BASENAME"]|options.output_file)+std::string(".out.h5"));
  
  //read in and set up real and imaginary domain
  imaginary_domain_data f_iomega(parms);
  real_domain_data f_omega(parms);

  f_iomega.write("input_data.dat");
  
  //set up pade class
  pade_interpolator P(parms);
  P.pade_interpolate(f_iomega, f_omega);
  
  f_omega.write(parms["OUTPUT"]);
  return 0;
}