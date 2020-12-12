---
permalink: arbitrary_deep_recursive_output
code: I9WNY7
usage:
  - https://leetcode.com/submissions/detail/361593754/?from=/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

---
{% assign page.title = page.permalink | split: "_" | join: " " | capitalize %}
{% include_relative README.md %}
# Code
```cpp
{% include_relative {{ page.code }}.cpp %}
```

# [Ideone it!](https://ideone.com/{{ page.code }})

{% for x in usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
