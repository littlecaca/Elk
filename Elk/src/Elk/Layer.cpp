#include <elkpch.h>
#include "Layer.h"

namespace Elk
{
	Layer::~Layer()
	{
	}

	Layer::Layer(const std::string &name) : m_DebugName(name)
	{
	}
}