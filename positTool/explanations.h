#ifndef EXPLANATIONS_H
#define EXPLANATIONS_H


#include <universal/number/posit/posit.hpp>
#include <universal/number/fixpnt/fixpnt.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "operation.h"


using namespace sw::universal;
const int _nbits = 32, _es = 2, _fbits = _nbits - _es - 3;
using Real = posit<_nbits, _es>;



template<size_t nbits, size_t es, size_t fbits = nbits - es - 3>
operation<sw::universal::posit<nbits, es>> showPositInfo(std::string input)
{
    long double d = stold(input);
    sw::universal::posit<nbits, es> p = d;

    //std::cin >> input;


    const int rawBits = nbits + 3;
    posit<rawBits, es> raw = d;
    int index = rawBits - nbits - 1;

    bool sign;	regime<nbits, es> reg;	exponent<nbits, es> exp;  fraction<fbits> frac;
    decode<nbits, es, p.fbits>(p.get(), sign, reg, exp, frac);

    operation<sw::universal::posit<nbits, es>> output("Input value: " + input);
    output.nextStep("Binary representation --- " + p.get().to_string());

    if (p.iszero())
    {
        output.nextSubstep("Zero");
        output.add("This bit pattern is special and exclusive to the zero value");
        return output;
    }
    if (p.isnar())
    {
        output.nextSubstep("Not a Real");
        output.add("This bit pattern is special and exclusive to the NaR value");
        return output;
    }
    std::string srefString = "(sign - regime";
    std::string srefValues = std::to_string(sign) + "-" + to_string(reg, false);

    if (to_string(exp, false).size() > 0)
    {
        srefString.append(" - exponent");
        srefValues.append("-" + to_string(exp, false));
        if (to_string(frac, false).size() > 0)
        {
            srefString.append(" - fraction");
            srefValues.append("-" + to_string(frac, false));
        }
    }
    srefString.append(")");

    output.nextSubstep(srefString);
    output.nextSubstep(srefValues);
    if (d != (double)p)
    {
        output.nextSubstep("Rounding");
        output.add("The nearest posit value to the user's input is " + sw::universal::to_string(p));
    }

    output.nextSubstep("Sign");
    if (sign)
        output.add("The sign bit is 1 so it is negative");
    else
        output.add("The sign bit is 0 so it is positive");

    output.nextSubstep("Regime");
    std::string regString = to_string(reg, false);
    output.add("The regime is " + regString);
    output.add("It is composed of m = " + std::to_string(regString.length()-1) + " "+ regString[0] + "s followed by a " + regString[regString.length()-1]);
    output.add("It is used to calculate useed^k");
    int useed = 1 << (1 << es);
    output.add("useed = 2^(2^es) = " + std::to_string(useed));
    output.add("k depends if the regime is 0s or 1s");
    int k = 0;
    if (regString[0] == '0')
    {
        k = -(regString.length()-1);
        output.add("The regime is 0s so k = -m = " + std::to_string(k));
    }
    else
    {
        k = (regString.length()-1)-1;
        output.add("The regime is 1s so k = m-1 = " + std::to_string(k));
    }
    output.nextSubstep("Exponent");
    std::string expString = to_string(exp, false);
    if (expString.length() < es)
    {
        output.add("We need to have " + std::to_string(es) + " exponent bits so any that did not fit in the " +std::to_string(nbits)+ " bits is considered 0");
    }
    while (expString.size() < es) expString.push_back('0');
    //The exponent is x which represents 2^y
    output.add("The exponent is " + expString);
    output.add("It represents 2^" + std::to_string((int)exp.scale()));
    output.nextSubstep("Fraction");
    std::string fracString = to_string(frac, false);
    if (fracString.size() == 0)
    {
        output.add("There are no fraction bits so the fraction is considered 0");
        fracString.push_back('0');
    }
    //The fraction is x which represents 1.x
    output.add("The fraction is " + to_string(frac, false));
    //The final value is axbxcxd
    output.nextSubstep("Final value");
    output.add("The final value is (1 + 0." + to_string(frac, false) + ") * 2^"+ std::to_string((int)exp.scale()) + " * " + std::to_string(useed) +"^" + std::to_string(k));
    output.add("The final value is 1." + to_string(frac, false) + " * 2^" + std::to_string(scale(p)));
    output.add("The final value is " + to_string(p));

    return output;
}

template<size_t nbits, size_t es, typename Ty>
operation<sw::universal::posit<nbits, es>>  conversion_to_posit(Ty rhs) {
    //constexpr size_t fbits = std::numeric_limits<Ty>::digits - 1;
    constexpr size_t fbits = nbits;

    using namespace sw::universal;

    internal::value<fbits> v((Ty)rhs);
    posit<nbits, es> p;

    operation<sw::universal::posit<nbits, es>> output("Convert " + std::to_string(rhs) + " to posit");

    output.nextStep("START");
    output.addHighlight(0);
    output.nextSubstep("Before starting we test for the special values 0 and NaR");
    if (v.iszero()) {
        p.setzero();
        output.add("input value is zero");
        output.add("The zero value has a special bit pattern reserved for it: " + p.get().to_string());
        output.result = 0;
        return output;
    }
    else {
        output.add(" input value is NOT zero");
    }
    if (v.isnan() || v.isinf()) {
        p.setnar();
        output.add(" input value is NaR");
        output.add("The NaR value has a special bit pattern reserved for it: " + p.get().to_string());
        output.result = NAR;
        return output;
    }
    else {
        output.add(" input value is NOT NaR");
    }

    bool _sign = v.sign();
    int _scale = v.scale();
    sw::universal::bitblock<fbits> fraction_in = v.fraction();

    int m;

    output.nextSubstep("First we need our number in binary scientific notation");
    {
        std::string bits = v.get_fixed_point().to_string();

        std::string notation = bits;
        notation.erase(nbits + 1);
        notation.insert(1, ".");

        output.add("Scientific notation binary value: ");
        if (_sign)
        {
            output.add(std::to_string(rhs) + " = " + "-" + notation + " * 2^" + std::to_string(_scale));
        }
        else
        {
            output.add(std::to_string(rhs) + " = " + notation + " * 2^" + std::to_string(_scale));
        }

        output.nextStep("FRACTION AND EXPONENT");
        output.addHighlight(1);
        output.addHighlight(2);
        output.addHighlight(3);

        output.nextSubstep("Fraction");

        output.add("Fraccion:");
        output.add(fraction_in.to_string());


        int e = _scale;
        bool r = (e >= 0);
        unsigned run = (r ? 1 + (e >> es) : -(e >> es));
        int k = (e >> es);
        if (_scale >= 0)
        {
            m = 1 + k;
        }
        else {
            m = -k;
        }

        int rbexp = (k << es);
        unsigned ebexp = _scale - rbexp;
        std::string expBin = std::bitset<es>(ebexp).to_string();


        output.nextSubstep("Exponent");
        output.add("The total exponent is represented by two values: the regime and the exponent");
        output.add("The regime's length is variable, and is calculated with the integer division of the positive exponent by 2^es rounded to -inf:");
        output.add(std::to_string(_scale) + " / " + std::to_string(1 << es) + " = " + std::to_string(k));
        output.add("Then if the result is positive we add one or if it's negative we change its sign");
        output.add("The length of the regime(m) is: " + std::to_string(m));
        output.add("This value represents = 2^" + std::to_string( rbexp));
        output.add("Then the exponent is the remaining value: ");
        //TODO Repasar esto
        output.add("e = " + std::to_string(ebexp));
        output.add("This value represents = 2^" + std::to_string(ebexp));
    }



    posit<fbits + es + 3, es> pst;

    output.nextStep("FINAL STEPS");
    output.addHighlight(6);

    if (check_inward_projection_range<nbits, es>(_scale)) {    // regime dominated
        // we are projecting to minpos/maxpos
        int k = calculate_unconstrained_k<nbits, es>(_scale);
        k < 0 ? p.setBitblock(minpos_pattern<nbits, es>(_sign)) : p.setBitblock(maxpos_pattern<nbits, es>(_sign));
        // we are done
        output.nextSubstep("Regime dominated");
        if (_scale > 0)
            output.add("The result is greater than maxpos, so it gets rounded to maxpos");
        else
            output.add("The result is smaller than minpos, so it gets rounded to minpos");

    }
    else {
        output.nextSubstep("Joining everything");
        output.add("Sign bit + " + std::to_string(m + 1) + " Regime bits + opposite bit + " + std::to_string(es) + " Exponent bits + fraction");
        output.addHighlight(4);
        output.addHighlight(5);



        bool c_sign = false;
        regime<fbits + es + 3, es> c_regime;
        c_regime.assign_regime_pattern(calculate_k<nbits, es>(_scale));
        exponent<fbits + es + 3, es> c_exponent;
        c_exponent.assign_exponent_bits(_scale, c_regime.regime_k(), c_regime.regime_run());
        fraction<fbits> c_fraction;
        c_fraction.set(fraction_in);
        output.add(std::to_string(c_sign) + " + " + to_string(c_regime, false) + " + " + to_string(c_exponent) + " + " + to_string(c_fraction));
        output.add(std::to_string(c_sign) + to_string(c_regime, false) + to_string(c_exponent) + to_string(c_fraction));

        construct<pst.nbits, pst.es, pst.fbits>(c_sign, c_regime, c_exponent, c_fraction, pst);


        output.nextSubstep("Truncate and round");
        output.add("We truncate the result to fit in " + std::to_string(nbits) + " bits");
        std::string str = pst.get().to_string();
        str.insert(nbits, "|");
        output.add(str);

        output.add("Before truncating we check if rounding is needed (round-to-nearest-even)");

        bool rnd = false;
        for (int i = nbits+1; i < str.length(); i++)
        {
            if (str[i] == '1') rnd = true;
        }
        bool rndUp = false;
        if (rnd)
        {
            if (str[nbits+1] == '1')
            {
                output.add("Rounding up");
                rndUp = true;
                if (str[nbits-1] == '0')
                {
                    rndUp = false;
                    for (int i = nbits+2; i < str.length(); i++)
                    {
                        if (str[i] == '1') rndUp = true;
                    }
                }
            }
            else
            {
                output.add("Rounding down");
                rndUp = false;
            }
        }
        else
        {
            output.add("Rounding is not needed");
        }



        bool cut_sign = false;
        regime<p.nbits, es> cut_regime;
        cut_regime.assign_regime_pattern(calculate_k<nbits, es>(_scale));
        exponent<p.nbits, es> cut_exponent;
        cut_exponent.assign_exponent_bits(_scale, cut_regime.regime_k(), cut_regime.regime_run());
        fraction<p.fbits> cut_fraction;

        sw::universal::bitblock<p.fbits> _fraction;
        for (int i = 0; i < p.fbits; i++)
        {
            _fraction[i] = fraction_in[fraction_in.size() - p.fbits + i];
        }
        cut_fraction.set(_fraction);
        construct<p.nbits, p.es, p.fbits>(cut_sign, cut_regime, cut_exponent, cut_fraction, p);

        bitblock<nbits> block = p.get();
        output.add("Truncated and rounded result: ");

        if (rndUp)
        {
            increment_bitset(block);
        }
        output.add(block.to_string());

        if (_sign)
        {
            block = twos_complement(block);
            output.add("The number is negative so we need to do 2's complement: ");
            output.add(block.to_string());
        }

        p.setBitblock(block);

    }
    output.nextSubstep("Final result");
    output.add(p.get().to_string() + " = " + sw::universal::to_string(p));
    output.result = p;
    return output;
}

//TODO comprobar que abits este bien
template<size_t nbits, size_t es, size_t fbits = nbits - es - 3, size_t abits = 2*(fbits + 1)>
operation<sw::universal::posit<nbits, es>> addition(sw::universal::posit<nbits,es> a, sw::universal::posit<nbits,es> b)
{
    posit<nbits, es> p;
    operation<sw::universal::posit<nbits, es>> output("a = " + sw::universal::to_string(a) + " b = " + sw::universal::to_string(b));

    output.nextStep("START");
    output.addHighlight(0);
    output.nextSubstep("Before starting we test for NaR");
    //TODO redondeo de los valores iniciales

    if (a.isnar() || b.isnar())
    {
        output.add("one of the values is NaR");
        return output;
    }
    else
    {
        output.add("none of the values are NaR");
    }

    int scl;
    bool sign = 0;

    bitblock<fbits + 1> aux = significant<nbits, es, fbits>(a);
    int aScale = scale(a);
    if (a == 0)
    {
        aux.setToZero();
        aScale = 0;
    }
    bitblock<abits> bitsa;
    for (int i = 1; i <= aux.size(); i++)
    {
        bitsa[bitsa.size() - i] = aux[aux.size() - i];
    }
    aux = significant<nbits, es, fbits>(b);
    int bScale = scale(b);
    if (b == 0)
    {
        aux.setToZero();
        bScale = 0;
    }
    bitblock<abits> bitsb;
    for (int i = 1; i <= aux.size(); i++)
    {
        bitsb[bitsb.size() - i] = aux[aux.size() - i];
    }
    std::string binA =  bitsa.to_string().insert(1,".");
    std::string binB = bitsb.to_string().insert(1,".");

    output.nextSubstep("We change the numbers to binary scientific notation");

    output.add(to_string(a) + " = " + (a < 0 ? "-" : "") + binA + " * 2^" + std::to_string(aScale));
    output.add(to_string(b) + " = " + (b < 0 ? "-" : "") + binB + " * 2^" + std::to_string(bScale));




    output.nextStep("RESULT");
    output.addHighlight(1);
    output.addHighlight(2);

    output.nextSubstep("Get both numbers to the same scale");
    output.add("First we find the higher exponent");
    if (a.sign() == b.sign()) sign = a.sign();
    else sign = abs(a) > abs(b) ? a.sign() : (abs(b) > abs(a) ? b.sign() : 0);

    if (aScale == bScale)
    {
        scl = aScale;
        output.add("Both exponents are equal so no change is needed");
    }
    else
    {
        if (aScale > bScale)
        {
            output.add("2^" + std::to_string(aScale) + " > 2^" + std::to_string(bScale));
            scl = aScale;
            bitsb >>= aScale - bScale;
        }
        else if (bScale > aScale)
        {
            output.add("2^" + std::to_string(bScale) + " > 2^" + std::to_string(aScale));
            scl = bScale;
            bitsa >>= bScale - aScale;
        }
        output.add("Shift the smaller number to the right to be in the same scale as the big number");

    }

    binA =  bitsa.to_string().insert(1,".");
    binB = bitsb.to_string().insert(1,".");


    output.add(to_string(a) + " = " + (a < 0 ? "-" : "") +  binA + " * 2^" + std::to_string(scl));
    output.add(to_string(b) + " = " + (b < 0 ? "-" : "") + binB + " * 2^" + std::to_string(scl));

    output.addHighlight(3);

    bitblock<abits + 1> rbits;
    std::string stringAux;
    if (a.sign() xor b.sign())
    {
        output.nextSubstep("Substraction");
        output.add("Substract the significands");
        if (bitsa.to_ullong() > bitsb.to_ullong())
        {
            subtract_unsigned(bitsa, bitsb, rbits);
        }
        else
        {
            subtract_unsigned(bitsb, bitsa, rbits);
        }
        if (a.sign())
        {
            stringAux.append(binB + " - " + binA + " = ");
        }
        else stringAux.append(binA + " - " + binB + " = ");
    }
    else {
        output.nextSubstep("Addition");
        output.add("Add the significands");
        add_unsigned(bitsa, bitsb, rbits);
        stringAux.append(binA + " + " + binB + " = ");
    }
    std::string binR = rbits.to_string().insert(2, ".");
    if (binR[0] == '0') binR.erase(0, 1);
    stringAux.append((sign? "-" : "") + binR);
    output.add(stringAux);


    output.addHighlight(4);

    if (rbits[rbits.size() - 1] == 1)
    {
        output.addHighlight(5);
        output.nextSubstep("Normalize: increase the exponent");

        output.add("We need the result in scientific notation so we shift the result to the right and increase the exponent");

        rbits >>= 1;
        scl++;

        output.add("Final exponent = 2^" + std::to_string(scl));
    }


    if (a != -b)
    {
        if (rbits[rbits.size() - 2] != 1)
        {
            output.addHighlight(5);
            output.nextSubstep("Normalize: decrease the exponent");
            output.add("We need the result in scientific notation so we shift the result to the left and decrease the exponent");
            while (rbits[rbits.size() - 2] != 1)
            {
                rbits <<= 1;
                scl--;
            }
            output.add("Final exponent = 2^" + std::to_string(scl));
        }

    }
    else scl = 0;

    output.nextSubstep("Final result");
    stringAux = (sign ? "-" : "");
    output.add("Final result = " + stringAux + rbits.to_string().erase(0, 1).insert(1, ".") + " * 2^" + std::to_string(scl));

    output.nextStep("CONVERSION");
    output.addHighlight(8);


    if (check_inward_projection_range<nbits, es>(scl)) {    // regime dominated
        output.nextSubstep("Regime dominated");
        if (scl > 0)
            output.add("The result is greater than maxpos, so it gets rounded to maxpos");
        else
            output.add("The result is smaller than minpos, so it gets rounded to minpos");
        // we are projecting to minpos/maxpos
        int k = calculate_unconstrained_k<nbits, es>(scl);
        k < 0 ? p.setBitblock(minpos_pattern<nbits, es>(sign)) : p.setBitblock(maxpos_pattern<nbits, es>(sign));
        // we are done
    }
    else
    {
        output.addHighlight(6);
        output.addHighlight(7);
        regime<nbits, es> regime;
        if (a != -b)
            regime.assign_regime_pattern(calculate_k<nbits, es>(scl));
        else regime.setzero();
        exponent<nbits, es> exponent;
        exponent.assign_exponent_bits(scl, regime.regime_k(), regime.regime_run());
        bitblock<fbits> fblock;
        fraction<fbits> fraction;
        rbits <<= 2;
        truncate<abits+1, fbits>(rbits, fblock);

        fraction.set(fblock);
        construct<p.nbits, p.es, p.fbits>(false, regime, exponent, fraction, p);

        output.nextSubstep("Posit value");
        bool rnd;
        std::string str;
        str = "0";
        str += to_string(regime, false);
        str += to_string(exponent, false);
        str += rbits.to_string();
        output.add(str);

        output.nextSubstep("Truncate and round");
        output.add("We need to truncate the result to fit in "  + std::to_string(nbits) + " bits");
        str.insert(nbits, "|");
        output.add(str);
        output.add("Before truncating we check if rounding is needed (round-to-nearest-even)");

        if (str[nbits+1] == '1')
        {
            rnd = true;
            if (str[nbits - 1] == '0')
            {
                rnd = false;
                for (int i = nbits + 2; i < str.length(); i++)
                {
                    if (str[i] == '1') rnd = true;
                }
            }
        }
        else
        {
            rnd = false;
        }
        if (rnd) output.add("Rounding is needed");
        else (output.add("Rounding is not needed"));

        bitblock<nbits> pblock = p.get();

        output.add("Truncated value = " + p.get().to_string());

        if (rnd)
        {
            increment_bitset(pblock);
            output.add("After rounding = " + pblock.to_string());
        }

        output.nextSubstep("Sign");

        if (sign)
        {
            output.add("The result is negative so we need to use 2's complement");
            pblock = twos_complement(pblock);
            output.add("After 2's complement = " + pblock.to_string());
        }
        else{
            output.add("The result is positive so we don't need to use 2's complement");
        }
        p.setBitblock(pblock);
        output.nextSubstep("Final result: ");

    }

    output.add(p.get().to_string() + " = " + sw::universal::to_string(p));

    return output;
}

template<size_t nbits, size_t es, size_t fbits = nbits - es - 3, size_t mbits = 2*(fbits+1)>
operation<sw::universal::posit<nbits, es>>  multiply(sw::universal::posit<nbits, es> a, sw::universal::posit<nbits, es> b)
{
    posit<nbits, es> p;
    operation<sw::universal::posit<nbits, es>> output("a = " + sw::universal::to_string(a) + " b = " + sw::universal::to_string(b));

    output.nextStep("START");
    output.addHighlight(0);
    output.nextSubstep("Before starting we test for NaR and zero");
    if (a.isnar() || b.isnar())
    {
        output.add("NaR");

        return output;
    }
    else output.add("None of the numbers are NaR");
    output.nextSubstep("Test for ZERO");
    if (a.iszero())
    {
        output.add("First number is 0, the result is always 0");
        return output;
    }
    else if (b.iszero())
    {
        output.add("Second number is 0, the result is always 0");
        return output;
    }
    else output.add("Both numbers are not 0");

    int scl = scale(a) + scale(b);
    bool sign = a.sign() xor b.sign();

    std::string binA =  significant<nbits, es, a.fbits>(a).to_string().insert(1,".");
    std::string binB =significant<nbits, es, b.fbits>(b).to_string().insert(1,".");

    output.nextSubstep("First we need our numbers in binary scientific notation");

    output.add(to_string(a) + " = " + binA + " * 2^" + std::to_string(scale(a)));
    output.add(to_string(b) + " = " + binB + " * 2^" + std::to_string(scale(b)));

    bitblock<mbits> block;
    multiply_unsigned<fbits + 1>(significant<nbits, es, a.fbits>(a), significant<nbits, es, b.fbits>(b), block);

    output.nextStep("RESULT");

    output.addHighlight(1);
    output.addHighlight(2);
    output.addHighlight(3);


    output.nextSubstep("Exponent");
    output.add("For the exponent we multiply the exponents from both numbers = 2^" + std::to_string(scl));
    output.add("2^" + std::to_string(scale(a)) + " * 2^" + std::to_string(scale(b)) + " = 2^" + std::to_string(scl));

    output.nextSubstep("Fraction");

    output.add("We multiply the significands");
    std::string binR = block.to_string().insert(2, ".");
    if (binR[0] == '0') binR.erase(0, 1);

    output.add(binA + " * " + binB + " = " + binR);

    if (block[block.size() - 1] == 1)
    {
        output.addHighlight(4);
        output.add("We need the result in scientific notation so we shift it to the right and increase the exponent");
        block >>= 1;
        scl++;
        binR.erase(2, 1);
        binR.insert(1, ".");
        output.add(binR);
        output.add("Final exponent = 2^" + std::to_string(scl));
    }
    std::string frac = binR;
    output.add("The fraction is " + frac.erase(0, 2));

    output.nextSubstep("Final result");
    output.add("Lastly we add the exponent");
    output.add("Final result = " + binR + " * 2^" + std::to_string(scl));

    output.nextStep("CONVERSION");
    output.addHighlight(7);


    if (check_inward_projection_range<nbits, es>(scl)) {    // regime dominated
        output.nextSubstep("Regime dominated");
        if (scl > 0)
            output.add("The result is greater than maxpos, so it gets rounded to maxpos");
        else
            output.add("The result is smaller than minpos, so it gets rounded to minpos");

        // we are projecting to minpos/maxpos
        int k = calculate_unconstrained_k<nbits, es>(scl);
        k < 0 ? p.setBitblock(minpos_pattern<nbits, es>(sign)) : p.setBitblock(maxpos_pattern<nbits, es>(sign));
        // we are done
    }
    else
    {
        output.addHighlight(5);
        output.addHighlight(6);

        regime<nbits, es> regime;
        regime.assign_regime_pattern(calculate_k<nbits, es>(scl));
        exponent<nbits, es> exponent;
        exponent.assign_exponent_bits(scl, regime.regime_k(), regime.regime_run());
        bitblock<fbits> fblock;
        fraction<fbits> fraction;
        block <<= 2;
        truncate<mbits, fbits>(block, fblock);

        fraction.set(fblock);
        construct<nbits, es, fbits>(false, regime, exponent, fraction, p);

        output.nextSubstep("Posit value");
        bool rnd;
        std::string str;
        str = "0";
        str += to_string(regime, false);
        str += to_string(exponent, false);
        str += block.to_string();
        output.add(str);
        output.nextSubstep("Truncate and round");
        output.add("We need to truncate the result to fit in "  + std::to_string(nbits) + " bits");
        str.insert(nbits, "|");
        output.add(str);
        output.add("Before truncating we check if rounding is needed (round-to-nearest-even)");

        if (str[nbits+1] == '1')
        {
            rnd = true;
            if (str[nbits - 1] == '0')
            {
                rnd = false;
                for (int i = nbits + 2; i < str.length(); i++)
                {
                    if (str[i] == '1') rnd = true;
                }
            }
        }
        else
        {
            rnd = false;
        }
        if (rnd) output.add("Rounding is needed");
        else (output.add("Rounding is not needed"));
        bitblock<nbits> pblock = p.get();
        output.add(pblock.to_string());

        output.add("Truncated value = " + p.get().to_string());

        if (rnd)
        {
            increment_bitset(pblock);
            output.add("After rounding = " + pblock.to_string());
        }

        output.nextSubstep("Sign");

        if (sign)
        {
            output.add("The result is negative so we need to use 2's complement");
            pblock = twos_complement(pblock);
            output.add("After 2's complement = " + pblock.to_string());
        }
        else{
            output.add("The result is positive so we don't need to use 2's complement");
        }
        p.setBitblock(pblock);

        output.nextSubstep("Final result: ");
    }

    output.add(p.get().to_string() + " = " + sw::universal::to_string(p));
    return output;
}

template<size_t nbits, size_t es, size_t fbits = nbits - es - 3, size_t divbits = 3 * (fbits +1) + 4>
operation<sw::universal::posit<nbits, es>> divide(sw::universal::posit<nbits, es> a, sw::universal::posit<nbits, es> b)
{
    posit<nbits, es> p;
    operation<sw::universal::posit<nbits, es>> output("a = " + sw::universal::to_string(a) + " b = " + sw::universal::to_string(b));

    output.nextStep("START");
    output.addHighlight(0);
    output.nextSubstep("Before starting we test for NaR and zero");
    if (a.isnar() || b.isnar())
    {
        output.add("NaR");
        return output;
    }
    else output.add("None of the numbers are NaR");
    output.nextSubstep("Test for ZERO");
    if (b.iszero())
    {
        output.add("Division by 0, the result is NaR(Not a Real)");
        return output;
    }
    else if (a.iszero())
    {
        output.add("First number is 0, the result is 0");
        return output;
    }
    else output.add("Both numbers are not 0");


    int scl = scale(a) - scale(b);
    bool sign = a.sign() xor b.sign();


    std::string binA =  significant<nbits, es, a.fbits>(a).to_string().insert(1,".");
    std::string binB =significant<nbits, es, b.fbits>(b).to_string().insert(1,".");

    output.nextSubstep("First we need our numbers in binary scientific notation");

    output.add(to_string(a) + " = " + binA + " * 2^" + std::to_string(scale(a)));
    output.add(to_string(b) + " = " + binB + " * 2^" + std::to_string(scale(b)));

    bitblock<divbits> block;
    divide_with_fraction(significant<nbits, es, a.fbits>(a), significant<nbits, es, b.fbits>(b), block);


    output.nextStep("RESULT");

    output.addHighlight(1);
    output.addHighlight(2);
    output.addHighlight(3);

    output.nextSubstep("Exponent");
    output.add("For the exponent we divide the exponents from both numbers = 2^" + std::to_string(scl));
    output.add("2^" + std::to_string(scale(a)) + " / 2^" + std::to_string(scale(b)) + " = 2^" + std::to_string(scl));


    output.nextSubstep("Fraction");

    output.add("We divide the fractions");
    std::string binR = block.to_string().insert(fbits+1, ".");
    if (binR[0] == '0') binR.erase(0, fbits);

    output.add(binA + " / " + binB + " = " + binR);


    if (block[block.size() - (fbits + 1)] != 1)
    {
        output.addHighlight(4);
        output.nextSubstep("Decrease the exponent");
        output.add("We need the result in scientific notation so we shift it to the left and decrease the exponent");
        while (block[block.size() - (fbits + 1)] != 1)
        {
            block <<= 1;
            scl--;
        }
        binR.erase(0, 2);
        binR.insert(1, ".");
        output.add(binR);
        output.add("Final exponent = 2^" + std::to_string(scl));
    }
    std::string frac = binR;
    output.add("The fraction is " + frac.erase(0, 2));

    output.nextSubstep("Final result");
    output.add("Lastly we add the exponent");
    output.add("Final result = " + binR + " * 2^" + std::to_string(scl));

    output.nextStep("CONVERSION");
    output.addHighlight(7);


    if (check_inward_projection_range<nbits, es>(scl)) {    // regime dominated
        output.nextSubstep("Regime dominated");
        if (scl > 0)
            output.add("The result is greater than maxpos, so it gets rounded to maxpos");
        else
            output.add("The result is smaller than minpos, so it gets rounded to minpos");

        // we are projecting to minpos/maxpos
        int k = calculate_unconstrained_k<nbits, es>(scl);
        k < 0 ? p.setBitblock(minpos_pattern<nbits, es>(sign)) : p.setBitblock(maxpos_pattern<nbits, es>(sign));
        // we are done
    }
    else
    {
        output.addHighlight(5);
        output.addHighlight(6);

        regime<nbits, es> regime;
        regime.assign_regime_pattern(calculate_k<nbits, es>(scl));
        exponent<nbits, es> exponent;
        exponent.assign_exponent_bits(scl, regime.regime_k(), regime.regime_run());
        bitblock<fbits> fblock;
        fraction<fbits> fraction;
        block <<= fbits+1;
        truncate<divbits, fbits>(block, fblock);

        fraction.set(fblock);
        construct<nbits, es, fbits>(false, regime, exponent, fraction, p);

        output.nextSubstep("Posit value");
        bool rnd;
        std::string str;
        str = "0";
        str += to_string(regime, false);
        str += to_string(exponent, false);
        str += block.to_string();
        output.add(str);
        output.nextSubstep("Truncate and round");
        output.add("We need to truncate the result to fit in "  + std::to_string(nbits) + " bits");
        str.insert(nbits, "|");
        output.add(str);
        output.add("Before truncating we check if rounding is needed (round-to-nearest-even)");

        if (str[nbits+1] == '1')
        {
            rnd = true;
            if (str[nbits - 1] == '0')
            {
                rnd = false;
                for (int i = nbits + 2; i < str.length(); i++)
                {
                    if (str[i] == '1') rnd = true;
                }
            }
        }
        else
        {
            rnd = false;
        }
        if (rnd) output.add("Rounding is needed");
        else (output.add("Rounding is not needed"));
        //output.add("Redondeamos y complemento a 2");

        bitblock<nbits> pblock = p.get();
        output.add(pblock.to_string());

        output.add("Truncated value = " + p.get().to_string());

        if (rnd)
        {
            increment_bitset(pblock);
            output.add("After rounding = " + pblock.to_string());
        }

        output.nextSubstep("Sign");

        if (sign)
        {
            output.add("The result is negative so we need to use 2's complement");
            pblock = twos_complement(pblock);
            output.add("After 2's complement = " + pblock.to_string());
        }
        else{
            output.add("The result is positive so we don't need to use 2's complement");
        }
        p.setBitblock(pblock);

        output.nextSubstep("Final result: ");
    }

    output.add(p.get().to_string() + " = " + sw::universal::to_string(p));

    return output;
}


#endif // EXPLANATIONS_H
