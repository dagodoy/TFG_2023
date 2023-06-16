#pragma once
// exceptions.hpp: definition of adaptiveint exceptions
//
// Copyright (C) 2017-2022 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.
#include <universal/common/exceptions.hpp>

namespace sw { namespace universal {

// base class for adaptiveint arithmetic exceptions
struct adaptiveint_arithmetic_exception
	: public std::runtime_error
{
	explicit adaptiveint_arithmetic_exception(const std::string& error) 
		: std::runtime_error(std::string("adaptiveint arithmetic exception: ") + error) {};
};

// divide by zero arithmetic exception for fixed-point
struct adaptiveint_divide_by_zero : public adaptiveint_arithmetic_exception {
	explicit adaptiveint_divide_by_zero(const std::string& error = "adaptiveint division by zero") 
		: adaptiveint_arithmetic_exception(error) {}
};

///////////////////////////////////////////////////////////////
// internal implementation exceptions

// base class for fixed-point internal exceptions
struct adaptiveint_internal_exception
	: public std::runtime_error
{
	explicit adaptiveint_internal_exception(const std::string& error) 
		: std::runtime_error(std::string("adaptiveint internal exception: ") + error) {};
};

struct adaptiveint_word_index_out_of_bounds : public adaptiveint_internal_exception {
	explicit adaptiveint_word_index_out_of_bounds(const std::string& error = "word index out of bounds") 
		: adaptiveint_internal_exception(error) {}
};

}} // namespace sw::universal
