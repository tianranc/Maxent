/*
 * Copyright (C) 1998-2016 ALPS Collaboration
 * 
 *     This program is free software; you can redistribute it and/or modify it
 *     under the terms of the GNU General Public License as published by the Free
 *     Software Foundation; either version 2 of the License, or (at your option)
 *     any later version.
 * 
 *     This program is distributed in the hope that it will be useful, but WITHOUT
 *     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *     FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 *     more details.
 * 
 *     You should have received a copy of the GNU General Public License along
 *     with this program; if not, write to the Free Software Foundation, Inc., 59
 *     Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * For use in publications, see ACKNOWLEDGE.TXT
 */

#pragma once

#include <alps/config.hpp> // needed to set up correct bindings
#include "maxent_config.hpp"
#include <Eigen/Core>

typedef Eigen::MatrixXd matrix_type;
typedef Eigen::MatrixXcd complex_matrix_type;
typedef Eigen::VectorXd vector_type;
typedef Eigen::MatrixXcd complex_vector_type;
typedef std::pair<vector_type, complex_vector_type> omega_complex_type;

///matrix-vector multiplication. 
inline vector_type maxent_prec_prod(const matrix_type &p, const vector_type &q) {
	return p*q;
}
///matrix-vector multiplication of transpose of matrix. 
inline vector_type maxent_prec_prod_trans(const matrix_type &p, const vector_type &q) {
	return p.transpose()*q;
}
///matrix-matrix multiplication. 
inline matrix_type maxent_prec_prod(const matrix_type &p, const matrix_type &q) {
	return p*q;
}
///matrix-matrix multiplication of transpose(p) with q. 
inline matrix_type maxent_prec_prod_trans(const matrix_type &p, const matrix_type &q) {
	return p.transpose()*q; 
}
