//// ���� �ݺ�, 0 �Է½� ����
//�ҵ漼�� ����Ͻðڽ��ϱ� ? 0)No 1)Yes
//���� �� �ҵ��� �Է��ϼ���(�� ����) : 3000
//("����� �ҵ漼�� %d �Դϴ�.", per) ���
//
////per ���� ����
//100000 < value : per = 45
//100000 >= value �̰� value > 50000 : per = 42
//50000 >= value �̰� value > 30000 : per = 40
//30000 >= value �̰� value > 15000 : per = 38
//15000 >= value �̰� value > 8800 : per = 35
//8800 >= value �̰� value > 4600 : per = 24
//4600 >= value �̰� value > 1200 : per = 15
//1200 >= value �̸� : per = 6

////�Լ� �̸� : standardWeight
////�ɹ� ���� : float height
////���� �� : float
////���� : (height - 100) * 0.9
//
////�Լ� �̸� : GetBMI
////�ɹ� ���� : float weight, float standardWeight
////���� �� : float
////���� : (weight - standardWeight)  * 100 / standardWeight
//
//// ���� �ݺ�, 0 �Է½� ����
//BMI�� ����Ͻðڽ��ϱ� ? 0)No 1)Yes
//�����Ը� �Է����ּ��� : weight�� �� �Է�
//Ű�� �Է����ּ��� : height�� �� �Է�
//bmi�� ���� ��� ����
//���		�񸸵� ��ġ
//10����		����
//10�ʰ� 20����	��ü��
//20 �ʰ�		��