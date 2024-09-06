---
publish: true
permalink: graph
title: Graph Algos
code:
  - graph

---
{% include_relative README.md %}
# Code

{% for x in page.code %}
```cpp
{% include_relative {{ x }}.h %}
```
{% endfor %}

{% for x in page.usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
