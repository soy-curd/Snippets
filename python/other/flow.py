import tensorflow as tf

a = tf.constant(1, name="a")
b = tf.constant(1, name="b")

c = a + b

print(c)
graph = tf.get_default_graph()
print(graph.as_graph_def())

with tf.Session() as sess:
    print(sess.run(c))