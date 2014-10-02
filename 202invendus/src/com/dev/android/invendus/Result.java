package com.dev.android.invendus;

import java.text.DecimalFormat;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class Result extends Activity {

	public static float a;
	public static float b;

	public static void affResult(Context context, int aArg, int bArg) {
		Result.a = aArg;
		Result.b = bArg;
		Intent t = new Intent(context, com.dev.android.invendus.Result.class);
		context.startActivity(t);
	}

	private static float prob(int x, int y, float a, float b) {
		return ((a - (float) x) * (b - (float) y))
				/ ((5 * a - 150) * (5 * b - 150));
	}

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.result);
		float tab[][] = new float[6][6];
		tab[0][0] = prob(10, 10, a, b);
		tab[0][1] = prob(10, 20, a, b);
		tab[0][2] = prob(10, 30, a, b);
		tab[0][3] = prob(10, 40, a, b);
		tab[0][4] = prob(10, 50, a, b);
		tab[0][5] = tab[0][0] + tab[0][1] + tab[0][2] + tab[0][3] + tab[0][4];

		tab[1][0] = prob(20, 10, a, b);
		tab[1][1] = prob(20, 20, a, b);
		tab[1][2] = prob(20, 30, a, b);
		tab[1][3] = prob(20, 40, a, b);
		tab[1][4] = prob(20, 50, a, b);
		tab[1][5] = tab[1][0] + tab[1][1] + tab[1][2] + tab[1][3] + tab[1][4];

		tab[2][0] = prob(30, 10, a, b);
		tab[2][1] = prob(30, 20, a, b);
		tab[2][2] = prob(30, 30, a, b);
		tab[2][3] = prob(30, 40, a, b);
		tab[2][4] = prob(30, 50, a, b);
		tab[2][5] = tab[2][0] + tab[2][1] + tab[2][2] + tab[2][3] + tab[2][4];

		tab[3][0] = prob(40, 10, a, b);
		tab[3][1] = prob(40, 20, a, b);
		tab[3][2] = prob(40, 30, a, b);
		tab[3][3] = prob(40, 40, a, b);
		tab[3][4] = prob(40, 50, a, b);
		tab[3][5] = tab[3][0] + tab[3][1] + tab[3][2] + tab[3][3] + tab[3][4];

		tab[4][0] = prob(50, 10, a, b);
		tab[4][1] = prob(50, 20, a, b);
		tab[4][2] = prob(50, 30, a, b);
		tab[4][3] = prob(50, 40, a, b);
		tab[4][4] = prob(50, 50, a, b);
		tab[4][5] = tab[4][0] + tab[4][1] + tab[4][2] + tab[4][3] + tab[4][4];

		tab[5][0] = tab[0][0] + tab[1][0] + tab[2][0] + tab[3][0] + tab[4][0]
				+ tab[5][0];
		tab[5][1] = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + tab[4][1]
				+ tab[5][1];
		tab[5][2] = tab[0][2] + tab[1][2] + tab[2][2] + tab[3][2] + tab[4][2]
				+ tab[5][2];
		tab[5][3] = tab[0][3] + tab[1][3] + tab[2][3] + tab[3][3] + tab[4][3]
				+ tab[5][3];
		tab[5][4] = tab[0][4] + tab[1][4] + tab[2][4] + tab[3][4] + tab[4][4]
				+ tab[5][4];
		tab[5][5] = tab[5][0] + tab[5][1] + tab[5][2] + tab[5][3] + tab[5][4]
				+ tab[5][5];

		float z0 = tab[0][0];
		float z1 = tab[0][1] + tab[1][0];
		float z2 = tab[0][2] + tab[1][1] + tab[2][0];
		float z3 = tab[0][3] + tab[1][2] + tab[2][1] + tab[3][0];
		float z4 = tab[0][4] + tab[1][3] + tab[2][2] + tab[3][1] + tab[4][0];
		float z5 = tab[1][4] + tab[2][3] + tab[3][2] + tab[4][1];
		float z6 = tab[2][4] + tab[3][3] + tab[4][2];
		float z7 = tab[3][4] + tab[4][3];
		float z8 = tab[4][4];

		float r0 = (tab[0][5] * (float) 10) + (tab[1][5] * (float) 20)
				+ (tab[2][5] * (float) 30) + (tab[3][5] * (float) 40)
				+ (tab[4][5] * (float) 50);
		float r1 = (tab[0][5] * (float) (10 * 10))
				+ (tab[1][5] * (float) (20 * 20))
				+ (tab[2][5] * (float) (30 * 30))
				+ (tab[3][5] * (float) (40 * 40))
				+ (tab[4][5] * (float) (50 * 50)) - (r0 * r0);
		float r2 = (tab[5][0] * (float) 10) + (tab[5][1] * (float) 20)
				+ (tab[5][2] * (float) 30) + (tab[5][3] * (float) 40)
				+ (tab[5][4] * (float) 50);
		float r3 = (tab[5][0] * (float) (10 * 10))
				+ (tab[5][1] * (float) (20 * 20))
				+ (tab[5][2] * (float) (30 * 30))
				+ (tab[5][3] * (float) (40 * 40))
				+ (tab[5][4] * (float) (50 * 50)) - (r2 * r2);
		float r4 = z0 * 20 + z1 * 30 + z2 * 40 + z3 * 50 + z4 * 60 + z5 * 70
				+ z6 * 80 + z7 * 90 + z8 * 100;
		float r5 = (z0 * (float) (20 * 20) + z1 * (float) (30 * 30) + z2
				* (float) (40 * 40) + z3 * (float) (50 * 50) + z4
				* (float) (60 * 60) + z5 * (float) (70 * 70) + z6
				* (float) (80 * 80) + z7 * (float) (90 * 90) + z8
				* (float) (100 * 100))
				- (r4 * r4);

		DecimalFormat f = new DecimalFormat();
		f.setMaximumFractionDigits(3);
		
		String v = String.format("%.3f", tab[0][0]);
		
		((TextView) findViewById(R.id.t00)).setText(f.format(tab[0][0]));
		((TextView) findViewById(R.id.t01)).setText(f.format(tab[0][1]));
		((TextView) findViewById(R.id.t02)).setText(f.format(tab[0][2]));
		((TextView) findViewById(R.id.t03)).setText(f.format(tab[0][3]));
		((TextView) findViewById(R.id.t04)).setText(f.format(tab[0][4]));
		((TextView) findViewById(R.id.t05)).setText(f.format(tab[0][5]));

		((TextView) findViewById(R.id.t10)).setText(f.format(tab[1][0]));
		((TextView) findViewById(R.id.t11)).setText(f.format(tab[1][1]));
		((TextView) findViewById(R.id.t12)).setText(f.format(tab[1][2]));
		((TextView) findViewById(R.id.t13)).setText(f.format(tab[1][3]));
		((TextView) findViewById(R.id.t14)).setText(f.format(tab[1][4]));
		((TextView) findViewById(R.id.t15)).setText(f.format(tab[1][5]));

		((TextView) findViewById(R.id.t20)).setText(f.format(tab[2][0]));
		((TextView) findViewById(R.id.t21)).setText(f.format(tab[2][1]));
		((TextView) findViewById(R.id.t22)).setText(f.format(tab[2][2]));
		((TextView) findViewById(R.id.t23)).setText(f.format(tab[2][3]));
		((TextView) findViewById(R.id.t24)).setText(f.format(tab[2][4]));
		((TextView) findViewById(R.id.t25)).setText(f.format(tab[2][5]));

		((TextView) findViewById(R.id.t30)).setText(f.format(tab[3][0]));
		((TextView) findViewById(R.id.t31)).setText(f.format(tab[3][1]));
		((TextView) findViewById(R.id.t32)).setText(f.format(tab[3][2]));
		((TextView) findViewById(R.id.t33)).setText(f.format(tab[3][3]));
		((TextView) findViewById(R.id.t34)).setText(f.format(tab[3][4]));
		((TextView) findViewById(R.id.t35)).setText(f.format(tab[3][5]));

		((TextView) findViewById(R.id.t40)).setText(f.format(tab[4][0]));
		((TextView) findViewById(R.id.t41)).setText(f.format(tab[4][1]));
		((TextView) findViewById(R.id.t42)).setText(f.format(tab[4][2]));
		((TextView) findViewById(R.id.t43)).setText(f.format(tab[4][3]));
		((TextView) findViewById(R.id.t44)).setText(f.format(tab[4][4]));
		((TextView) findViewById(R.id.t45)).setText(f.format(tab[4][5]));

		((TextView) findViewById(R.id.t50)).setText(f.format(tab[5][0]));
		((TextView) findViewById(R.id.t51)).setText(f.format(tab[5][1]));
		((TextView) findViewById(R.id.t52)).setText(f.format(tab[5][2]));
		((TextView) findViewById(R.id.t53)).setText(f.format(tab[5][3]));
		((TextView) findViewById(R.id.t54)).setText(f.format(tab[5][4]));
		((TextView) findViewById(R.id.t55)).setText(f.format(tab[5][5]));

		((TextView) findViewById(R.id.z0)).setText(f.format(z0));
		((TextView) findViewById(R.id.z1)).setText(f.format(z1));
		((TextView) findViewById(R.id.z2)).setText(f.format(z2));
		((TextView) findViewById(R.id.z3)).setText(f.format(z3));
		((TextView) findViewById(R.id.z4)).setText(f.format(z4));
		((TextView) findViewById(R.id.z5)).setText(f.format(z5));
		((TextView) findViewById(R.id.z6)).setText(f.format(z6));
		((TextView) findViewById(R.id.z7)).setText(f.format(z7));
		((TextView) findViewById(R.id.z8)).setText(f.format(z8));
		((TextView) findViewById(R.id.z9)).setText(f.format(z0 + z1 + z2 + z3
				+ z4 + z5 + z6 + z7 + z8));

		((TextView) findViewById(R.id.r0)).setText(f.format(r0));
		((TextView) findViewById(R.id.r1)).setText(f.format(r1));
		((TextView) findViewById(R.id.r2)).setText(f.format(r2));
		((TextView) findViewById(R.id.r3)).setText(f.format(r3));
		((TextView) findViewById(R.id.r4)).setText(f.format(r4));
		((TextView) findViewById(R.id.r5)).setText(f.format(r5));
	}

}
