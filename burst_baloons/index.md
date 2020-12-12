---
permalink: burst_baloons
title: Burst Baloons
code: g8RhXy

---

{% include_relative README.md %}
# Code
```cpp
{% include_relative {{ page.code }}.cpp %}
```

# [Ideone it!](https://ideone.com/{{ page.code }})

{% assign n = usage.size %}
{% if n > 0 %}
# Usage
{% for i in (1..n) %}
 - [Usage {{ i }}]({{usage[i-1]}})
{% endfor %}
{% endif %}
