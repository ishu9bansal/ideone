---
publish: true
permalink: 12_ball_puzzle
title: 12 Ball Puzzle
code:
  - dIZtHl

---
{% include_relative README.md %}
# Code

{% for x in page.code %}
```cpp
{% include_relative {{ x }}.cpp %}
```
# [Ideone it!](https://ideone.com/{{ x }})
{% endfor %}

{% for x in page.usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
