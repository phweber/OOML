﻿/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include <core/Difference.h>
#include <core/IndentWriter.h>

#include <iostream>

void Difference::genScad(IndentWriter& writer) const
{
	writer << "difference() {" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::genScad(writer);
	}
	writer << "} // End difference" << std::endl;
}

void Difference::printAst(IndentWriter& writer) const
{
	writer << "// DIFFERENCE()" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::printAst(writer);
	}
}

Component operator-(Component const& lhs, Component const& rhs)
{
  CompositeComponent result(Difference::create());
  result << lhs.get() << rhs.get();
  return result;
}
