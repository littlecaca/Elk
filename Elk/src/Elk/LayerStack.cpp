#include <elkpch.h>
#include "LayerStack.h"

namespace Elk
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer *layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer *layer)
	{
		m_LayerInsert = m_Layers.insert(m_LayerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer *overlay)
	{
		m_Layers.push_back(overlay);
	}

	// The layer will not be destroyed
	void LayerStack::PopLayer(Layer *layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			if (it <= m_LayerInsert)
				--m_LayerInsert;
			m_Layers.erase(it);
		}
	}

	void LayerStack::PopOverlay(Layer *overlay)
	{

		PopLayer(overlay);
	}
}