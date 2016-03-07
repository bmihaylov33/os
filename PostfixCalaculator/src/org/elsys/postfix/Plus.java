package org.elsys.postfix;

public class Plus extends BinaryOperation{
	
	public Plus() {
		// TODO Auto-generated constructor stub
		super("+");
	}
		 
	@Override
	public double calc(double v1, double v2) {
		return v1 + v2;
	}
}