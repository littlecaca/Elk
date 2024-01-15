#include <elkpch.h>
#include "LayerStack.h"

namespace Elk
{
	LayerStack::LayerStack() : m_LayerInsertIndex(0)
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer *layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer *layer)
	{
		m_Layers.insert(m_Layers.begin() + m_LayerInsertIndex, layer);
		++m_LayerInsertIndex;
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer *overlay)
	{
		m_Layers.push_back(overlay);
		overlay->OnAttach();
	}

	// The layer will not be destroyed
	void LayerStack::PopLayer(Layer *layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			if (it < m_Layers.begin() + m_LayerInsertIndex)
				--m_LayerInsertIndex;
			m_Layers.erase(it);
			layer->OnDetach();
		}
	}

	void LayerStack::PopOverlay(Layer *overlay)
	{
		PopLayer(overlay);
	}
}