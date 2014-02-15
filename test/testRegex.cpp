/*
	testRegex.cpp	WJ114
*/
/*
 * Copyright (c) 2014, Walter de Jong
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "oolib"

using namespace oo;

int main(void) {
	Regex re(R"((\d+))");
	print("re: %v", &re);
	Array<String> m = re.match("123");
	print("re.match: %q", &m);
	print();

	re = R"(the (\w+\s\w+) jumped over the (\w+\s\w+))";
	print("re: %v", &re);
	m = re.match("the yellow dog jumped over the hairy cat");
	print("re.match: %q", &m);

	// \w+ does only matches ASCII chars
//	m = re.match(u8"the quick 狐 jumped over the lazy 犬");
//	print("re.match: %q", &m);
	print();

	re = R"(the \w+\s\w+ jumped over the \w+\s\w+)";
	print("re: %v", &re);
	m = re.match("the yellow dog jumped over the hairy cat");
	print("re.match: %s", (!m) ? "FAIL" : "OK");
	m = re.match("the quick brown fox jumped over the lazy dog");
	print("re.match test2: %s", (!m) ? "OK" : "FAIL");
	print();

	// match UTF-8 strings
	re = u8R"(交易金额：(\d+)元)";
	print("re: %v", &re);
	m = re.match(u8R"(交易金额：600元)");
	print("re.match: %q", &m);
	print();

	re = R"((\d+))";
	print("re: %v", &re);
	m = re.search(u8R"(交易金额：600元)");
	print("re.search: %q", &m);
	print();
	return 0;
}

// EOB
