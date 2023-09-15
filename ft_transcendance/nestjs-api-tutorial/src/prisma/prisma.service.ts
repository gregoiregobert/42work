import { Injectable } from '@nestjs/common';
import { Prisma, PrismaClient } from '@prisma/client';

@Injectable()
export class PrismaService extends PrismaClient {
	constructor() {
		super({
			datasources: {
				db: {
					url: "postgresql://postgre:123@localhost:5434/mydb?schema=public"
				}
			}
		})
	}
}
