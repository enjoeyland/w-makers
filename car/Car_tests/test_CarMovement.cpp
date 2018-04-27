//
// Created by Enjoeyland on 2018-04-27.
//

#include <gtest/gtest.h>
#include"Car/CarMovement.h"

using testing::Eq;

namespace {
#define carMovement (CarMovement) CarMovementAnalog(1,2,3,4, 5.0);

	class ClassDeclaration : public testing::Test {
	public:
		ClassDeclaration() {
			carMovement;
		}
	};
}
TEST_F(ClassDeclaration, test1) {
	ASSERT_EQ("","");
}